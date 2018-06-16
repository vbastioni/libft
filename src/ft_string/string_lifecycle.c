#include "ft_string.h"

t_string				*string_new(size_t first)
{
	t_string			*buf;

	if ((buf = (t_string *)ft_memalloc(sizeof(t_string))) == NULL)
		return (NULL);
	if ((buf->buffer = ft_strnew(first)) == NULL)
	{
		ft_memdel((void **)&buf);
		return (NULL);
	}
	buf->size = first;
	return (buf);
}

char				*string_del(t_string **buf)
{
	char			*str;

	if (buf == NULL || *buf == NULL)
		return (NULL);
	str = ft_strndup((*buf)->buffer, (*buf)->used);
	ft_strdel(&((*buf)->buffer));
	ft_memdel((void **)buf);
	return (str);
}

void				string_clear(t_string *buf)
{
	ft_bzero(buf->buffer, buf->used);
	buf->used = 0;
}

void				string_nuke(t_string **buf)
{
	ft_strdel(&((*buf)->buffer));
	ft_memdel((void **)buf);
}
