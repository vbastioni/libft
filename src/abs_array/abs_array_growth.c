#include "abs_array.h"

int                     absarr_grow(t_absarr *arr)
{
    unsigned char       *new_content;

    new_content = ft_memalloc(arr->content_size * arr->capacity * 2);
    if (new_content == NULL)
        return (0);
    ft_memmove(new_content, arr->content, arr->content_size * arr->capacity);
    ft_memdel((void **)&arr->content);
    arr->content = new_content;
    arr->capacity *= 2;
    return (1);
}

int                     absarr_shiftn(t_absarr *arr, size_t n)
{
    if ((arr->length + n) == arr->capacity)
    {
        if (absarr_grow(arr) == 0)
            return (0);
    }
    ft_memmove(absarr_get(arr, n), arr->content,
                arr->content_size * arr->capacity);
    return (1);
}

int                     absarr_shift(t_absarr *arr)
{
    return (absarr_shiftn(arr, 1));
}
