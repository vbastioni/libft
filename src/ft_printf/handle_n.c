#include "ft_printf.h"

int					fpf_handle_n(va_list *ap, t_flag *flag)
{
	int				*ptr;

	(void)flag;
	ptr = va_arg(*ap, int *);
	*ptr = fpf_buf_gettotal(NULL);
	return (1);
}
