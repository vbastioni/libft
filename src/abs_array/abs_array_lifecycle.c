#include "abs_array.h"

t_absarr                *absarr_with_capacity(size_t content_size,
                                                size_t capacity)
{
    t_absarr            *arr;

    capacity = round_bit_long(capacity);
    arr = ft_memalloc(sizeof(t_absarr));
    arr->content_size = content_size;
    arr->capacity = capacity;
    arr->content = ft_memalloc(content_size * capacity);
    return (arr);

}

t_absarr                *absarr_new(size_t content_size)
{
    return (absarr_with_capacity(content_size, 16));
}
