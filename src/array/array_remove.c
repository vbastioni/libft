#include "array.h"

void					*array_dequeue(t_array *array)
{
	return (array_remove(array, array->index - 1));
}
void					*array_pop(t_array *array)
{
	return (array_remove(array, 0));
}

void					*array_remove(t_array *array, size_t pos)
{
	void				*ret;

	if (pos >= array->index)
		return (NULL);
	ret = array->content[pos];
	array->content[pos] = NULL;
	while (42)
	{
		if (pos == (array->index - 1))
			break ;
		array->content[pos]
			= array->content[pos + 1];
		pos++;
	}
	array->index--;
	return (ret);
}
