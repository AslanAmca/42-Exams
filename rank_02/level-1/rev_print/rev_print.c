#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int len = 0;
		while (argv[1][len] != '\0')
			len++;
		
		int last_index = len - 1;
		while (last_index >= 0)
		{
			write(1, &argv[1][last_index], 1);
			last_index--;
		}
	}
	write(1, "\n", 1);
}
