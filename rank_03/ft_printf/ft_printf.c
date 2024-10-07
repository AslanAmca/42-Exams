#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

int print_char(char chr)
{
	write(1, &chr, 1);
	return 1;
}

int print_string(char *str)
{
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return 6;
	}

	int len = 0;
	while (*str != '\0')
	{
		len += print_char(*str);
		str++;
	}
	return len;
}

int print_int(int nbr)
{
	int len = 0;
	long number = nbr;

	if (nbr < 0)
	{
		len += print_char('-');
		number = -number;
	}
	if (number <= 9)
	{
		len += print_char(number + '0');
	}
	else
	{
		len += print_int(number / 10);
		len += print_int(number % 10);
	}
	return len;
}

int print_hex(unsigned int nbr)
{
	int len = 0;

	if (nbr <= 9)
	{
		len += print_char(nbr + '0');
	}
	else if (nbr <= 15)
	{
		len += print_char('a' + (nbr - 10));
	}
	else
	{
		len += print_hex(nbr / 16);
		len += print_hex(nbr % 16);
	}
	return len;
}

int ft_printf(const char *format, ...)
{
	int len = 0;
	va_list ap;

	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
				len += print_char('%');
			else if (*format == 's')
				len += print_string(va_arg(ap, char *));
			else if (*format == 'd')
				len += print_int(va_arg(ap, int));
			else if (*format == 'x')
				len += print_hex(va_arg(ap, unsigned int));
		}
		else
			len += print_char(*format);
		format++;
	}
	va_end(ap);
	return len;
}