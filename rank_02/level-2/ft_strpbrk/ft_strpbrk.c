// s1 içerisinde ki karakterlerden herhangi biri s2 içerisinde var mı diye bakar.
// eğer varsa o karakterin adresini geriye döner.
// eğer yoksa NULL döner.
char *ft_strpbrk(const char *s1, const char *s2)
{
	while (*s1 != '\0')
	{
		int i = 0;
		while (s2[i] != '\0')
		{
			if (*s1 == s2[i])
				return (char *)s1;
			i++;
		}
		s1++;
	}
	return NULL;
}
