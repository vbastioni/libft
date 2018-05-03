#include "ft_string.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1++ == '\0')
			return (0);
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 == *s2)
	{
		if (*s1++ == '\0' || --n <= 0)
			return (0);
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
