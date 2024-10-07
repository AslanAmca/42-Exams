int max(int *tab, unsigned int len)
{
	if (tab == 0 || len == 0)
		return 0;

	int max = *tab;
	int i = 0;
	while (i <= len)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return max;
}
