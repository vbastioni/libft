#include "qbuf.h"

int						qbuf_addc(t_qbuf *buf, char c)
{
	if (buf->used + 1 == buf->size)
	{
		if (qbuf_grow(buf) == 0)
			return (0);
	}
	buf->buffer[buf->used] = c;
	buf->used++;
	return (1);
}

int						qbuf_add(t_qbuf *buf, char *str)
{
	if (str == NULL)
		return (0);
	return (qbuf_addn(buf, str, ft_strlen(str)));
}

int						qbuf_addl(t_qbuf *buf, long l)
{
	char				lbuf[30];

    ft_bzero(lbuf, 30);
    ft_ltobuf(l, 10, 0, lbuf);
	return (qbuf_add(buf, lbuf));
}

static inline size_t	lnearest_pow(size_t n, size_t b)
{
	while (b < n)
		b <<= 1;
	return (b);
}

int						qbuf_addn(t_qbuf *buf, char *str, size_t n)
{
	size_t				total;

	if (buf == NULL || str == NULL || n == (size_t)-1)
		return (0);
	total = buf->used + n;
	if (total < buf->size)
	{
		ft_strncpy(buf->buffer + buf->used, str, n);
		buf->used = total;
		return (1);
	}
	if (qbuf_grown(buf, lnearest_pow(total << 1, buf->size)) == 0)
		return (0);
	ft_strncat(buf->buffer, str, n);
	buf->used = total;
	return (1);
}
