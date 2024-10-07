#include <unistd.h>

static void print_int(int number)
{
	if (number <= 9)
	{
		char chr = number + '0';
		write(1, &chr, 1);
	}
	else
	{
		print_int(number / 10);
		print_int(number % 10);
	}
}

int main(int argc, char **argv)
{
	if (argc == 1)
		write(1, "0", 1);
	else
		print_int(argc - 1);
	write(1, "\n", 1);
}
