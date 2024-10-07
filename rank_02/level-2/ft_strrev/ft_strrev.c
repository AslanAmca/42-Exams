char *ft_strrev(char *str)
{
	int len = 0;
	while (str[len] != '\0')
		len++;

	int last_index = len - 1;
	
	int i = 0;
	while (i < last_index)
	{
		char temp = str[i];
		str[i] = str[last_index];
		str[last_index] = temp;
		i++;
		last_index--;
	}
	return str;
}
