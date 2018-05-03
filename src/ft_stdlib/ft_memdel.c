#include "ft_stdlib.h"

void            ft_memdel(void **data)
{
    free(*data);
    *data = NULL;
}
