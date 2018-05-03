#include "ft_string.h"

char                *ft_strcpy(char *dst, const char *src)
{
	char            *s;

	s = dst;
	while ((*s++ = *src++))
		;
	return (dst);
}

char		        *ft_strncpy(char *dst, const char *src, size_t len)
{
	char	        *beg;

	beg = dst;
	while (len > 0 && *src)
	{
		*dst++ = *src++;
		len--;
	}
	while (len--)
		*dst++ = '\0';
	return (beg);
}
