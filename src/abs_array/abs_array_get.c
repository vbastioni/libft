#include "abs_array.h"

unsigned char           *absarr_get(struct s_absarr *arr, size_t n)
{
    return ((unsigned char *)((void *)arr->content + n * arr->content_size));
}
