#include <unistd.h>
#include <stdlib.h>

char *get_next_line(int fd)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	char *buffer = malloc(10000);
	char chr;
	int i = 0;
	int readed_byte = 0;

	readed_byte = read(fd, &chr, 1);
	if (readed_byte < 1)
	{
		free(buffer);
		return NULL;
	}

	while (readed_byte > 0)
	{
		buffer[i] = chr;
		if (chr == '\n')
			break;
		i++;
		readed_byte = read(fd, &chr, 1);
	}

	if (readed_byte == -1)
	{
		free(buffer);
		return NULL;
	}

	if (buffer[i] == '\n')
		i++;

	buffer[i] = '\0';
	return buffer;
}