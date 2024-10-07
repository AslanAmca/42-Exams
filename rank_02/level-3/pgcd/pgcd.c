#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		int number1 = atoi(argv[1]);
		int number2 = atoi(argv[2]);

		int result = 1;
		int i = 2;
		while (i <= number1 && i <= number2)
		{
			if (number1 % i == 0 && number2 % i == 0)
				result = i;
			i++;
		}
		printf("%d", result);
	}
	printf("\n");
}
