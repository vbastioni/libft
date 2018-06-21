#include "ft_string.h"

int					string_grow(t_string *buf)
{
	return (string_grown(buf, buf->size * 2));
}

int					string_grown(t_string *buf, size_t n)
{
	char			*str;

	if ((str = ft_strnew(n)) == NULL)
		return (0);
	buf->size = n;
	ft_strcpy(str, buf->buffer);
	ft_strdel(&buf->buffer);
	buf->buffer = str;
	return (1);
}
