#include <stdlib.h>

static char *trim_space(char *str)
{
	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;
	return str;
}

static int get_word_count(char *str)
{
	int count = 0;
	while (*str != '\0')
	{
		if (*str == ' ' || *str == '\t' || *str == '\n')
		{
			if (*(str + 1) != ' ' && *(str + 1) != '\t' && *(str + 1) != '\n' && *(str + 1) != '\0')
				count++;
		}
		str++;
	}
	return count + 1;
}

static char *get_next_word(char *str)
{
	int len = 0;
	while (str[len] != ' ' && str[len] && '\t' && str[len] != '\n')
		len++;

	if (len == 0)
		return NULL;

	char *word = malloc(sizeof(char) * (len + 1));

	int i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return word;
}

static int get_next_word_index(char *str)
{
	int i = 0;
	while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\0')
		i++;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	return i;
}

char **ft_split(char *str)
{
	str = trim_space(str);
	int word_count = get_word_count(str);

	char **strings = malloc(sizeof(char *) * (word_count + 1));

	int i = 0;
	while (i < word_count)
	{
		strings[i] = get_next_word(str);
		str = str + get_next_word_index(str);
		i++;
	}
	strings[i] = NULL;

	return strings;
}
