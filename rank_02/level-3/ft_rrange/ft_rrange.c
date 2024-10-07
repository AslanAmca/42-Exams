#include <stdlib.h>

int *ft_rrange(int start, int end)
{
	int len = 0;
	int counter = 0;
	int *array = NULL;

	if (start > end)
	{
		len = start - end + 1;
		counter = -1;
	}
	else
	{
		len = end - start + 1;
		counter = 1;
	}

	array = malloc(sizeof(int) * len);
	len--;
	while (0 <= len)
	{
		array[len] = start;
		len--;
		start = start + counter;
	}

	return array;
}
