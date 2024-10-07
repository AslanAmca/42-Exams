unsigned char reverse_bits(unsigned char octet)
{
	unsigned char result = 0;
	int i = 0;
	while (i <= 7)
	{
		if (octet >> i & 1)
			result = result | 1 << 7 - i;
		i++;
	}
	return result;
}
