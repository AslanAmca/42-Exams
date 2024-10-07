#include <unistd.h>

static int ft_atoi(char *str)
{
	int result = 0;
	int sign = 1;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;

	if (*str == '+')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}

	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}

	return result * sign;
}

static int is_prime(int number)
{
	if (number < 2)
		return 0;

	int i = 2;
	while (i < number)
	{
		if (number % i == 0)
			return 0;
		i++;
	}
	return 1;
}

static void print_int(int number)
{
	if (number < 10)
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
	if (argc != 2)
	{
		write(1, "0\n", 2);
		return 0;
	}

	int number = ft_atoi(argv[1]);
	int result = 0;
	int i = 0;
	while (i <= number)
	{
		if (is_prime(i))
			result += i;
		i++;
	}
	print_int(result);
	write(1, "\n", 1);
}
