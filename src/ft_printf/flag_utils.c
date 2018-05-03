#include "ft_printf.h"

void		fpf_flag_clear(t_flag *flag)
{
	flag->id = -1;
	flag->min = 0;
	flag->pre = 0;
	flag->sz_flag = 0;
	flag->flag = 0;
}
