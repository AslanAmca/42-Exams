#include <stddef.h>

static int ft_strchr(const char *str, char chr)
{
	while (*str != '\0')
	{
		if (*str == chr)
			return 1;
		str++;
	}
	return 0;
}

size_t ft_strspn(const char *s, const char *accept)
{
	int len = 0;
	while (s[len] != '\0' && ft_strchr(accept, s[len]))
		len++;
	return len;
}
