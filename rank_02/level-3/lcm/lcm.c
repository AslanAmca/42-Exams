unsigned int lcm(unsigned int a, unsigned int b)
{
	int low = a < b ? a : b;
	int big = a > b ? a : b;

	int i = 1;
	while (1)
	{
		if (low * i % big == 0)
			return low * i;
		i++;
	}

}
