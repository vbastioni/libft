#include "ft_string.h"

#include <unistd.h>

char				*string_dump(t_string *buf)
{
	char			*ret;

	ret = ft_strdup(buf->buffer);
	ft_bzero(buf->buffer, buf->used);
	buf->used = 0;
	return (ret);
}

void				string_printclose(t_string **buf, int fd)
{
	write(fd, (*buf)->buffer, (*buf)->used);
	string_nuke(buf);
}
