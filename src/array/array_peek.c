#include "array.h"

void			*array_first(t_array *array)
{
	if (array->index == 0)
		return (NULL);
	return (array->content[0]);
}

void			*array_front(t_array *array)
{
	return (array_first(array));
}

void			*array_last(t_array *array)
{
	if (array->index == 0)
		return (NULL);
	return (array->content[array->index - 1]);
}

void			*array_back(t_array *array)
{
	return (array_last(array));
}

void			*array_peek(t_array *array)
{
	return (array_last(array));
}
