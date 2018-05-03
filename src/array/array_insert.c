#include "array.h"

int                     array_append(t_array *array, void *from)
{
	return (array_insert(array, from, array->index));
}

int						array_enqueue(t_array *array, void *from)
{
	return (array_insert(array, from, array->index));
}

int						array_prepend(t_array *array, void *from)
{
	return (array_insert(array, from, 0));
}

int						array_push(t_array *array, void *from)
{
	return (array_insert(array, from, 0));
}

int                     array_insert(t_array *array, void *from, size_t pos)
{
	size_t				i;

	if (pos > array->index || pos == (size_t)-1)
		return (1);
	if (array->index == array->size && array_grow(array))
		return (-1);
	i = array->index;
	while (i != pos)
	{
		array->content[i] = array->content[i - 1];
		i--;
	}
	array->content[pos] = from;
	array->index++;
	return (0);
}
