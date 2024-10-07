#include <unistd.h>

int main(void)
{
	for(int i = 1; i <= 100; i++)
	{
		if (i % 3 == 0 && i % 5 == 0)
			write(1, "fizzbuzz", 8);
		else if (i % 3 == 0)
			write(1, "fizz", 4);
		else if (i % 5 == 0)
			write(1, "buzz", 4);
		else if (i >= 10)
		{
			char ten = i / 10 + '0';
			char one = i % 10 + '0';
			write(1, &ten, 1);
			write(1, &one, 1);
		}
		else
		{
			char number = i + '0';
			write(1, &number, 1);
		}
		write(1, "\n", 1);
	};
}
