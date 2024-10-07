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
	{
		write(1, "\n", 1);
		return 0;
	}

	int number = ft_atoi(argv[1]);
	int i = 1;
	while (i <= 9)
	{
		print_int(i);
		write(1, " x ", 3);
		print_int(number);
		write(1, " = ", 3);
		print_int(i * number);
		write(1, "\n", 1);
		i++;
	}
}
