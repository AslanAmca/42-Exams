#include <stddef.h>

// s içerisinde ki karakterlerden herhangi biri reject içerisinde var mı diye bakar.
// eğer varsa s içerisinde karakterin index'ini döner.
// eğer yoksa s'in uzunluğunu döner.
size_t ft_strcspn(const char *s, const char *reject)
{
	int i = 0;
	while (s[i] != '\0')
	{
		int j = 0;
		while (reject[j] != '\0')
		{
			if (s[i] == reject[j])
				return i;
			j++;
		}
		i++;
	}
	// eğer hiçbir karakter yoksa s uzunluğunu dön
	return i;
}
