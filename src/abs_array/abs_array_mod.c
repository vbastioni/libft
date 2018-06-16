#include "abs_array.h"

unsigned char           *absarr_prepend(t_absarr *arr, unsigned char *value)
{
    absarr_shift(arr);
    ft_memmove(arr->content, value, arr->content_size);
    arr->length += 1;
    return (arr->content);
}
   
unsigned char           *absarr_append(t_absarr *arr, unsigned char *value)
{
    unsigned char       *last;

    if (arr->length == arr->capacity)
        absarr_grow(arr);
    last = absarr_get(arr, arr->length - 1);
    ft_memmove(last, value, arr->content_size);
    arr->length += 1;
    return (last);
}

