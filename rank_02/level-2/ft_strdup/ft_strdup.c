#include <stdlib.h>

char *ft_strdup(char *src)
{
	int len = 0;
	while (src[len] != '\0')
		len++;

	char *string = malloc(sizeof(char) * (len + 1));
	if (string == NULL)
		return NULL;

	int i = 0;
	while (src[i] != '\0')
	{
		string[i] = src[i];
		i++;
	}
	string[i] = '\0';
	
	return string;
}
