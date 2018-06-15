#ifndef QBUF_H
# define QBUF_H

# include "ft_stdlib.h"
# include "ft_string.h"

typedef struct s_qbuf	t_qbuf;

struct					s_qbuf
{
	char				*buffer;
	size_t				used;
	size_t				size;
};

t_qbuf					*qbuf_new(size_t first);

int						qbuf_add(t_qbuf *buf, char *str);
int						qbuf_addn(t_qbuf *buf, char *str, size_t n);
int						qbuf_addc(t_qbuf *buf, char c);

int						qbuf_grow(t_qbuf *buf);
int						qbuf_grown(t_qbuf *buf, size_t n);

char					*qbuf_dump(t_qbuf *buf);
char					*qbuf_del(t_qbuf **buf);
void					qbuf_clear(t_qbuf *buf);
void					qbuf_nuke(t_qbuf **buf);
void					qbuf_printclose(t_qbuf **buf, int fd);
int						qbuf_addl(t_qbuf *buf, long l);

int                     qbuf_cmp(t_qbuf *lhs, t_qbuf *rhs);
int                     qbuf_strcmp(t_qbuf *lhs, const char *rhs);

#endif
