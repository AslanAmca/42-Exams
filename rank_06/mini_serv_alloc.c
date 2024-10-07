#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <netdb.h>

typedef struct s_client
{
	int fd;
	int id;
	char *message;
} t_client;

t_client clients[1024];
fd_set active_fds, read_fds, write_fds;
int server_socket_fd, largest_socket_fd, id = 0;

void print_error(char *message)
{
	write(2, message, strlen(message));
	write(2, "\n", 1);
	exit(1);
}

int extract_message(char **buf, char **msg)
{
	char *newbuf;
	int i;

	*msg = 0;
	if (*buf == 0)
		return (0);
	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
			if (newbuf == 0)
				print_error("Fatal error");
			strcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = 0;
			*buf = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}

char *str_join(char *buf, char *add)
{
	char *newbuf;
	int len;

	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		print_error("Fatal error");
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}

void send_message_to_all(char *message, int except_client_fd)
{
	for (int fd = 0; fd <= largest_socket_fd; fd++)
	{
		if (FD_ISSET(fd, &write_fds) && fd != except_client_fd)
			send(fd, message, strlen(message), 0);
	}
}

void init_server(int port)
{
	server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server_socket_fd == -1)
		print_error("Fatal error");

	struct sockaddr_in servaddr;
	bzero(&servaddr, sizeof(servaddr));

	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433);
	servaddr.sin_port = htons(port);

	if ((bind(server_socket_fd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) == -1)
		print_error("Fatal error");

	if (listen(server_socket_fd, 10) == -1)
		print_error("Fatal error");

	largest_socket_fd = server_socket_fd;

	FD_ZERO(&active_fds);
	FD_SET(server_socket_fd, &active_fds);
}

void handle_new_connection()
{
	int new_client_fd = accept(server_socket_fd, NULL, NULL);
	if (new_client_fd == -1)
		return;

	t_client *client = &clients[new_client_fd];
	client->fd = new_client_fd;
	client->id = id;
	client->message = NULL;
	id++;

	FD_SET(client->fd, &active_fds);

	if (client->fd > largest_socket_fd)
		largest_socket_fd = client->fd;

	char buffer[64];
	sprintf(buffer, "server: client %d just arrived\n", client->id);
	send_message_to_all(buffer, client->fd);
}

void handle_client_message(int fd)
{
	t_client *client = &clients[fd];

	char recv_buffer[8192];
	int readed_byte = recv(client->fd, recv_buffer, sizeof(recv_buffer) - 1, 0);

	if (readed_byte <= 0)
	{
		FD_CLR(client->fd, &active_fds);

		close(client->fd);

		if (client->message)
		{
			free(client->message);
			client->message = NULL;
		}

		char buffer[64];
		sprintf(buffer, "server: client %d just left\n", client->id);
		send_message_to_all(buffer, client->fd);
	}
	else
	{
		recv_buffer[readed_byte] = '\0';
		client->message = str_join(client->message, recv_buffer);
		char *message = NULL;

		while (extract_message(&client->message, &message))
		{
			char buffer[64 + strlen(message)];
			sprintf(buffer, "client %d: %s", client->id, message);
			send_message_to_all(buffer, client->fd);

			free(message);
			message = NULL;
		}
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
		print_error("Wrong number of arguments");

	init_server(atoi(argv[1]));

	while (1)
	{
		read_fds = write_fds = active_fds;

		if ((select(largest_socket_fd + 1, &read_fds, &write_fds, NULL, NULL)) == -1)
			continue;

		for (int fd = 0; fd <= largest_socket_fd; fd++)
		{
			if (!FD_ISSET(fd, &read_fds))
				continue;

			if (fd == server_socket_fd)
				handle_new_connection();
			else
				handle_client_message(fd);
		}
	}

	close(server_socket_fd);
	return 0;
}