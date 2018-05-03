#include "ft_printf.h"

void				fpf_correct_fmt(t_flag *flag)
{
	if (((flag->flag & 4) || flag->min == 0) && (flag->sz_flag & 3) == 2)
	{
		flag->min = flag->pre;
		flag->sz_flag ^= 3;
	}
}
