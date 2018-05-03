#ifndef FT_STDIO_H
# define FT_STDIO_H

# include <unistd.h>
# include "ft_string.h"

void					ft_putstr(const char *str);
void					ft_putstr_fd(int fd, const char *str);

void					ft_putendl(const char *str);
void					ft_putendl_fd(int fd, const char *str);

#endif
