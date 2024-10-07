#include <unistd.h>

static void ft_strcat(char *dest, char *src)
{
	while (*dest != '\0')
		dest++;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
}

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		ft_strcat(argv[1], argv[2]);

		int i = 0;
		while (argv[1][i] != '\0')
		{
			int found = 0;
			int j = 0;
			while (j < i)
			{
				if (argv[1][i] == argv[1][j])
					found = 1;
				j++;
			}
			if (found == 0)
				write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}
