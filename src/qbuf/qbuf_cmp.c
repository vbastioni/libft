#include "qbuf.h"

int             qbuf_cmp(t_qbuf *lhs, t_qbuf *rhs)
{
    return (ft_strncmp(lhs->buffer, rhs->buffer,
                        lhs->used > rhs->used ? lhs->used : rhs->used));
}

int             qbuf_strcmp(t_qbuf *lhs, const char *rhs)
{
    size_t      len;

    len = ft_strlen(rhs);
    return (ft_strncmp(lhs->buffer, rhs, lhs->used > len ? lhs->used : len));
}
