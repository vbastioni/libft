#include "ft_printf.h"

int				fpf_handle_flag(const char *str, size_t *i, va_list ap)
{
	t_flag		flag;

	fpf_flag_clear(&flag);
	while (str[*i] != '\0')
	{
		if (flag_get(str, i, ap, &flag) == 0)
			break ;
	}
	if ((flag.sz_flag & 6) == 4)
	{
		flag.sz_flag |= 6;
		flag.pre = 0;
	}
	fpf_correct_fmt(&flag);
	return (fpf_flag_print(str, i, &flag, ap));
}
