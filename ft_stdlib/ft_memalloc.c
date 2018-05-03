#include "ft_stdlib.h"

void                    *ft_memalloc(size_t size)
{
    void                *ret;

    ret = malloc(size);
    if (ret == NULL)
        return (NULL);
    memset(ret, 0, size);
    return (ret);
}
