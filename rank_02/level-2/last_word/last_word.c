#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int len = 0;
		while (argv[1][len] != '\0')
			len++;

		// son karakter index'ini bul
		len--;
		while (argv[1][len] == ' ' || argv[1][len] == '\t')
			len--;

		// ilk karakter index'ini bul
		while (argv[1][len] != ' ' && argv[1][len] != '\t' && argv[1][len] != '\0')
			len--;

		// ilk karakter'ten son karaktere kadar yazdır
		len++;
		while (argv[1][len] != ' ' && argv[1][len] != '\t' && argv[1][len] != '\0')
		{
			write(1, &argv[1][len], 1);
			len++;
		}
	}
	write(1, "\n", 1);
}
