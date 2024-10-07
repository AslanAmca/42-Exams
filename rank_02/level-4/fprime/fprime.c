#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int number = atoi(argv[1]);

		if (number <= 1)
		{
			printf("%d\n", number);
			return 0;
		}

		int i = 2;
		while (number != 1)
		{
			if (number % i == 0)
			{
				number = number / i;
				printf("%d", i);
				if (number != 1)
					printf("*");
			}
			else
				i++;
		}
	}
	printf("\n");
}
