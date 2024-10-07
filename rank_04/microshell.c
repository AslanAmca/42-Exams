#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define IN 0
#define OUT 1
#define ERR 2

void print_string(char *string)
{
	while (*string != '\0')
	{
		write(ERR, string, 1);
		string++;
	}
}

int print_error(char *message, char *parameter)
{
	print_string("error: ");
	print_string(message);
	if (parameter != NULL)
		print_string(parameter);
	print_string("\n");
	return 1;
}

int cd_handler(char *path, int i)
{
	if (i != 2)
		return print_error("cd: bad arguments", NULL);
	if (chdir(path) == -1)
		return print_error("cd: cannot change directory to ", path);
	return 0;
}

int command_handler(char **argv, char **envp, int i)
{
	char *command = *argv;
	int has_pipe = argv[i] != NULL && strcmp(argv[i], "|") == 0;
	int pipe_fd[2];

	if (has_pipe && pipe(pipe_fd) == -1)
		return print_error("fatal", NULL);

	int pid = fork();
	if (pid == -1)
		return print_error("fatal", NULL);
	if (pid == 0)
	{
		argv[i] = NULL;
		if (has_pipe && (dup2(pipe_fd[1], OUT) == -1 || close(pipe_fd[0]) == -1 || close(pipe_fd[1]) == -1))
			return print_error("fatal", NULL);
		execve(command, argv, envp);
		return print_error("cannot execute ", command);
	}

	int status;
	waitpid(pid, &status, 0);
	if (has_pipe && (dup2(pipe_fd[0], IN) == -1 || close(pipe_fd[0]) == -1 || close(pipe_fd[1]) == -1))
		return print_error("fatal", NULL);
	return WIFEXITED(status) && WEXITSTATUS(status);
}

int main(int argc, char **argv, char **envp)
{
	if (argc < 2)
		return 1;

	int status = 0;
	int i = 0;
	while (argv[i] != NULL && argv[++i] != NULL)
	{
		argv = argv + i;
		i = 0;
		while (argv[i] != NULL && strcmp(argv[i], "|") != 0 && strcmp(argv[i], ";") != 0)
			i++;
		if (strcmp(*argv, "cd") == 0)
			status = cd_handler(*(argv + 1), i);
		else if (i > 0)
			status = command_handler(argv, envp, i);
	}
	return status;
}