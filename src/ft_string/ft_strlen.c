#include "ft_string.h"

size_t				ft_strlen(const char *str)
{
	const char		*beg;

	beg = str;
	while (*str != '\0')
		str++;
	return (str - beg);
}
