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
	char message[64000];
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
	int readed_byte = recv(client->fd, recv_buffer, sizeof(recv_buffer), 0);

	if (readed_byte <= 0)
	{
		FD_CLR(client->fd, &active_fds);

		close(client->fd);

		bzero(client->message, strlen(client->message));

		char buffer[64];
		sprintf(buffer, "server: client %d just left\n", client->id);
		send_message_to_all(buffer, client->fd);
	}
	else
	{
		for (int i = 0, j = strlen(client->message); i < readed_byte; i++, j++)
		{
			client->message[j] = recv_buffer[i];

			if (client->message[j] == '\n')
			{
				client->message[j] = '\0';

				char buffer[64 + strlen(client->message)];
				sprintf(buffer, "client %d: %s\n", client->id, client->message);
				send_message_to_all(buffer, client->fd);

				bzero(client->message, strlen(client->message));
				j = -1;
			}
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