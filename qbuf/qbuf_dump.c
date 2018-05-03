#include "qbuf.h"

#include <unistd.h>

char				*qbuf_dump(t_qbuf *buf)
{
	char			*ret;

	ret = ft_strdup(buf->buffer);
	ft_bzero(buf->buffer, buf->used);
	buf->used = 0;
	return (ret);
}

void				qbuf_printclose(t_qbuf **buf, int fd)
{
	write(fd, (*buf)->buffer, (*buf)->used);
	qbuf_nuke(buf);
}
