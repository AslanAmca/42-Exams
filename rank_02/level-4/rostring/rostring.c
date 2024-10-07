#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		int word_start = 0;
		int word_end = 0;
		int multiple_word = 0;

		int i = 0;
		while (argv[1][i] == ' ' || argv[1][i] == '\t')
			i++;
		word_start = i;

		while (argv[1][i] != ' ' && argv[1][i] != '\t' && argv[1][i] != '\0')
			i++;
		word_end = i;

		// ikinci kelimeye geçebilmek için boşlukları at
		while (argv[1][i] == ' ' || argv[1][i] == '\t')
			i++;

		// ikinci kelimenin başlangıcı
		while (argv[1][i] != '\0')
		{
			multiple_word = 1;

			// arada birden fazla boşluk varsa atla
			if ((argv[1][i] == ' ' || argv[1][i] == '\t') && (argv[1][i + 1] == ' ' || argv[1][i + 1] == '\t'))
			{
				i++;
				continue;
			}
			write(1, &argv[1][i], 1);
			i++;
		}

		if (multiple_word)
			write(1, " ", 1);

		while (word_start < word_end)
		{
			write(1, &argv[1][word_start], 1);
			word_start++;
		}
	}
	write(1, "\n", 1);
}
