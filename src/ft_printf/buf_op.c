#include "ft_printf.h"

int					fpf_buf_addc(const char c)
{
	t_buf			*buf;

	buf = fpf_buf_get();
	string_addc(buf->buf, c);
	return (1);
}

int					fpf_buf_addfillers(int ws, size_t sz)
{
	t_buf			*buf;

	buf = fpf_buf_get();
	while (sz > BIG_WS_SZ)
	{
		string_addn(buf->buf, ws ? BIG_WS : BIG_00, BIG_WS_SZ);
		sz -= BIG_WS_SZ;
	}
	string_addn(buf->buf, ws ? BIG_WS : BIG_00, sz);
	return (1);
}

int					fpf_buf_add(const char *str, size_t n)
{
	t_buf			*buf;

	buf = fpf_buf_get();
	string_addn(buf->buf, (char *)str, n);
	return (n);
}
