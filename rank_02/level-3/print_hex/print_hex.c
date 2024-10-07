#include <unistd.h>

static int ft_atoi(char *str)
{
	int result = 0;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return result;
}

static void print_hex(int number)
{
	if (number <= 9)
	{
		char chr = number + '0';
		write(1, &chr, 1);
	}
	else if (number <= 15)
	{
		char chr = number - 10 + 'a';
		write(1, &chr, 1);
	}
	else
	{
		print_hex(number / 16);
		print_hex(number % 16);
	}

}

int main(int argc, char **argv)
{
	if (argc == 2)
		print_hex(ft_atoi(argv[1]));
	write(1, "\n", 1);
}
