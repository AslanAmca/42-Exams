static int get_digit(char chr)
{
	if (chr >= '0' && chr <= '9')
		return chr - '0';

	if (chr >= 'A' && chr <= 'F')
		return chr - 'A' + 10;

	if (chr >= 'a' && chr <= 'f')
		return chr - 'a' + 10;
}

int ft_atoi_base(const char *str, int str_base)
{
	int result = 0;
	int sign = 1;

	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str != '\0')
	{
		result = result * str_base + get_digit(*str);
		str++;
	}
	return (result * sign);
}
