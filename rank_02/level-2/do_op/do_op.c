#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if (argc == 4)
	{
		int number1 = atoi(argv[1]);
		int number2 = atoi(argv[3]);
		char op = argv[2][0];

		if (op == '+')
			printf("%d", number1 + number2);
		if (op == '-')
			printf("%d", number1 - number2);
		if (op == '*')
			printf("%d", number1 * number2);
		if (op == '/')
			printf("%d", number1 / number2);
		if (op == '%')
			printf("%d", number1 % number2);
	}
	printf("\n");
}
