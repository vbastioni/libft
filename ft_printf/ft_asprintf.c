#include "ft_printf.h"

int				ft_asprintf(char **str, const char *format, ...)
{
	va_list		ap;
	int			printed;

	va_start(ap, format);
	printed = ft_vasprintf(str, format, ap);
	va_end(ap);
	return (printed);
}

int				ft_vasprintf(char **str, const char *format, va_list ap)
{
	t_buf		*buf;

	buf = fpf_buf_get();
	buf->type = FPF_A;
	buf->len = UINT_MAX;
	buf->out.out = str;
	return (fpf_worker(format, ap));
}

int				ft_asnprintf(char **str, size_t size, const char *format, ...)
{
	va_list		ap;
	int			printed;

	va_start(ap, format);
	printed = ft_vasnprintf(str, size, format, ap);
	va_end(ap);
	return (printed);
}

int				ft_vasnprintf(char **str, size_t size, const char *format,
								va_list ap)
{
	t_buf		*buf;

	buf = fpf_buf_get();
	buf->type = FPF_A;
	buf->len = size;
	buf->out.out = str;
	return (fpf_worker(format, ap));
}
