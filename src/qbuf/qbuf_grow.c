#include "qbuf.h"

int					qbuf_grow(t_qbuf *buf)
{
	return (qbuf_grown(buf, buf->size * 2));
}

int					qbuf_grown(t_qbuf *buf, size_t n)
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
