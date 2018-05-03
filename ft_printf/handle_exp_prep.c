#include "ft_printf.h"

static void			resolve_double(t_exp *e, int negpre)
{
	if (negpre)
	{
		while ((e->d) < 1)
		{
			(e->sz)++;
			(e->d) *= 10;
		}
	}
	else
	{
		while ((e->d) > 10)
		{
			(e->sz)++;
			(e->d) /= 10;
		}
	}
}

void				prepare_double(t_exp *e)
{
	int				neg;

	neg = e->d < 0;
	if (neg)
	{
		e->d = -(e->d);
		e->buf[e->len++] = '-';
	}
	resolve_double(e, (e->d) < 1);
}
