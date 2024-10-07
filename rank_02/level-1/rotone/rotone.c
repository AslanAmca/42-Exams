#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int i = 0;
		while (argv[1][i] != '\0')
		{
			char chr = argv[1][i];
			
			if ((chr >= 'a' && chr <= 'y') || (chr >= 'A' && chr <= 'Y'))
				chr = chr + 1;
			else if (chr == 'z' || chr == 'Z')
				chr = chr - 25;

			write(1, &chr, 1);
			i++;
		}
	}
	write(1, "\n", 1);
}
