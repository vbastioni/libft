#include <stdio.h>

#include "array.h"

#include <unistd.h>

static size_t			array_growth_to_fit(t_array *array, size_t n)
{
    size_t              o;
    size_t              cnt;

    cnt = 0;
    o = array->size;
    n += array->index;
    while (o < n)
    {
        if (o & 0x8000000000000000)
            return ((size_t)-1);
        o <<= 1;
        cnt++;
    }
    return (cnt);
}

int                     array_catn(t_array *array, void **from, size_t n)
{
    size_t              growth;
    size_t              i;

    growth = array_growth_to_fit(array, n);
    if (growth == (size_t)-1)
        return (-2);
    if (growth && array_grown(array, growth))
        return (-1);
    i = 0;
    while (i < n)
    {
		array->content[array->index] = from[i];
        i++;
        array->index++;
    }
  	return (0);
}

static size_t			arr_len(void **arr)
{
	size_t				len;

	len = 0;
	while (arr[len] != NULL)
		len++;
	return (len);
}

int                     array_cat(t_array *array, void **from)
{
    size_t              n;

    n = arr_len(from);
    if (n == 0)
        return (0);
    return (array_catn(array, from, n));
}
