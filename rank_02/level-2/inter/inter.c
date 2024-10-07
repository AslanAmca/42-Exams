#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		char ascii[256];

		int i = 0;
		while (argv[2][i] != '\0')
		{
			ascii[(int)argv[2][i]] = 1;
			i++;
		}

		i = 0;
		while (argv[1][i] != '\0')
		{
			if (ascii[(int)argv[1][i]] == 1)
			{
				write(1, &argv[1][i], 1);
				ascii[(int)argv[1][i]] = 2;
			}
			i++;
		}
	}
	write(1, "\n", 1);
}
