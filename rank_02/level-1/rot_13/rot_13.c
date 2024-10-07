#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int i = 0;
		while (argv[1][i] != '\0')
		{
			char chr = argv[1][i];

			if ((chr >= 'a' && chr <= 'm') || (chr >= 'A' && chr <= 'M'))
				chr = chr + 13;
			else if ((chr >= 'n' && chr <= 'z') || (chr >= 'N' && chr <= 'Z'))
				chr = chr - 13;

			write(1, &chr, 1);
			i++;
		}
	}
	write(1, "\n", 1);
}
