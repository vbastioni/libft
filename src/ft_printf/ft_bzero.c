#include "ft_printf.h"

void		fpf_bzero(void *s, size_t n)
{
	char	*ss;
	size_t	i;

	if (n == 0)
		return ;
	i = 0;
	ss = (char *)s;
	while (i < n)
	{
		*(ss + i) = 0;
		i++;
	}
}
