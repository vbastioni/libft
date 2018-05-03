#include "ft_printf.h"

static void			bufferize(t_exp *e, t_flag *flag)
{
	int				i;
	size_t			pre;

	pre = (flag->sz_flag & 6) ? flag->pre : 6;
	(e->rem) = pre > 49 ? pre - 49 : 0;
	pre = (e->rem) != 0 ? 49 : pre;
	i = (int)e->d;
	e->buf[e->len++] = i + '0';
	e->d -= i;
	e->buf[e->len++] = '.';
	e->d += rounder(pre + 1);
	while (pre > 0)
	{
		e->d *= 10;
		i = (int)e->d;
		e->buf[e->len++] = i + '0';
		e->d -= i;
		pre--;
	}
}

static u_char		get_spec(t_flag *flag, t_exp *e)
{
	return (((flag->flag & (1 << 10)) == 0)
			| (((flag->sz_flag & 1) && flag->min > e->len) << 1)
			| (((flag->flag & (1 << 12)) != 0) << 2)
			| (((flag->flag & (1 << 9)) != 0) << 3));
}

static void			endbuffering(t_exp *e, t_flag *flag, u_char *spec)
{
	e->buf[e->len++] = flag->c == 'e' ? 'e' : 'E';
	e->buf[e->len++] = e->negpre ? '-' : '+';
	e->buf[e->len++] = (e->sz > 9 ? e->sz / 10 : 0) + '0';
	e->buf[e->len++] = (e->sz % 10) + '0';
	if (e->rem == 0 && ((*spec) & 3) == 3)
	{
		if (((*spec) & 12) == 12)
			fpf_buf_addc('+');
		fpf_buf_addfillers(((*spec) & 8) == 0,
							flag->min - e->len - (((*spec) & 4) == 4));
		if (((*spec) & 12) == 4)
			fpf_buf_addc('+');
	}
	fpf_buf_add(e->buf, e->len);
	if ((*spec) == 2)
		fpf_buf_addfillers(1, (flag->min - e->len - e->rem
								- (e->rem != 0 ? 51 : 0)));
}

static void			prepare_exp(t_exp *e, va_list *ap)
{
	e->buf = fpf_buf_get()->tmp_buf;
	e->len = 0;
	e->sz = 0;
	ft_bzero(e->buf, FT_TMPBSZ);
	e->d = va_arg(*ap, double);
	e->negpre = (e->d > 0 && e->d < 1) || (e->d < 0 && e->d > -1);
	prepare_double(e);
}

int					fpf_handle_exp(va_list *ap, t_flag *flag)
{
	u_char			spec;
	t_exp			e;

	prepare_exp(&e, ap);
	bufferize(&e, flag);
	spec = get_spec(flag, &e);
	if (e.rem != 0)
	{
		if ((spec & 3) == 3)
		{
			if ((spec & 12) == 12)
				fpf_buf_addc('+');
			fpf_buf_addfillers((spec & 8) == 0,
								flag->min - e.rem - 55 - ((spec & 4) == 4));
			if ((spec & 12) == 4)
				fpf_buf_addc('+');
		}
		fpf_buf_add(e.buf, e.len);
		fpf_buf_addfillers(0, e.rem);
		e.len = 0;
	}
	endbuffering(&e, flag, &spec);
	return (1);
}
