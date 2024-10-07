#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int word_start = 0;
		int word_end = 0;

		int i = 0;
		while (argv[1][i] != '\0')
			i++;
		i--;

		while (i >= 0)
		{
			while (argv[1][i] == ' ' || argv[1][i] == '\t' && argv[1][i] != '\0')
				i--;

			word_end = i;
			while (argv[1][i] != ' ' && argv[1][i] != '\t' && argv[1][i] != '\0')
				i--;
			word_start = i + 1;

			while (word_start <= word_end)
			{
				write(1, &argv[1][word_start], 1);
				word_start++;
			}

			if (i != -1)
				write(1, " ", 1);
		}
	}
	write(1, "\n", 1);
}
