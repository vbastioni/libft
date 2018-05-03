#include "ft_string.h"

void                *ft_memset(void *b, int c, size_t len)
{
    u_char          *data;

    data = (u_char *)b;
    while (len--)
    {
        *data = c;
        data++;
    }
    return (b);
}

void                ft_bzero(void *b, size_t len)
{
    ft_memset(b, 0, len);
}
