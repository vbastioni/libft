#include "ft_string.h"

char	            *ft_strcat(char *s1, const char *s2)
{
	char            *tmp;

	tmp = s1;
	while (*s1)
		s1++;
	while (*s2)
		*s1++ = (unsigned char)*s2++;
	*s1 = '\0';
	return (tmp);
}

char	            *ft_strncat(char *s1, const char *s2, size_t n)
{
	char	        *s;

	if (n == 0)
		return (s1);
	s = s1;
	while (*s1)
		s1++;
	while (1)
	{
		*(s1++) = *s2;
		if (*(s2++) == '\0')
			break ;
		if (--n == 0)
			break ;
	}
	if (*(s1 - 1) != '\0')
		*s1 = '\0';
	return (s);
}
