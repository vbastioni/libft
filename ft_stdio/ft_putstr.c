#include "ft_stdio.h"

void					ft_putstr_fd(int fd, const char *str)
{
	size_t				len;

	len = ft_strlen(str);
	write(fd, str, len);
}

void					ft_putstr(const char *str)
{
	ft_putstr_fd(STDOUT_FILENO, str);
}

void					ft_putendl_fd(int fd, const char *str)
{
	ft_putstr_fd(fd, str);
	write(fd, "\n", 1);
}

void					ft_putendl(const char *str)
{
	ft_putendl_fd(STDOUT_FILENO, str);
}
