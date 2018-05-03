#include "ft_printf.h"

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	int			printed;

	va_start(ap, format);
	printed = ft_vprintf(format, ap);
	va_end(ap);
	return (printed);
}

int				ft_sprintf(char *str, const char *format, ...)
{
	va_list		ap;
	int			printed;

	va_start(ap, format);
	printed = ft_vsprintf(str, format, ap);
	va_end(ap);
	return (printed);
}

int				ft_snprintf(char *str, size_t size, const char *format, ...)
{
	va_list		ap;
	int			printed;

	va_start(ap, format);
	printed = ft_vsnprintf(str, size, format, ap);
	va_end(ap);
	return (printed);
}

int				ft_dprintf(int fd, const char *format, ...)
{
	va_list		ap;
	int			printed;

	if (fd == -1)
		return (-1);
	va_start(ap, format);
	printed = ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (printed);
}
