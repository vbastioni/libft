#include "ft_string.h"

int             string_cmp(t_string *lhs, t_string *rhs)
{
    return (ft_strncmp(lhs->buffer, rhs->buffer,
                        lhs->used > rhs->used ? lhs->used : rhs->used));
}

int             string_strcmp(t_string *lhs, const char *rhs)
{
    size_t      len;

    len = ft_strlen(rhs);
    return (string_strncmp(lhs, rhs, len));
}

int             string_strncmp(t_string *lhs, const char *rhs, size_t len)
{
    return (ft_strncmp(lhs->buffer, rhs, lhs->used > len ? lhs->used : len));
}
