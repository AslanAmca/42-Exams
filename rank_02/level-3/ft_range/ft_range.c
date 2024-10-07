#include <stdlib.h>

int *ft_range(int start, int end)
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

	int i = 0;
	while (i < len)
	{
		array[i] = start;
		i++;
		start = start + counter;
	}

	return array;
}
