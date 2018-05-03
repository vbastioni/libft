#include "array.h"

int                     array_grown(t_array *array, size_t n)
{
    void                **old;
    void                **new;
	size_t				new_size;
    size_t              i;

    old = array->content;
	new_size = array->size << n;
    if ((new = ft_memalloc(sizeof(void *) * new_size)) == NULL)
        return (1);
    i = 0;
	memcpy(new, old, sizeof(void *) * array->index);
	array->content = new;
    free(old);
    array->size <<= n;
    return (0);
}

int                     array_grow(t_array *array)
{
    return (array_grown(array, 1));
}
