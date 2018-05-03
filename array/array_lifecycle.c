#include "array.h"

struct s_array          *array_new(void)
{
    t_array             *ret;

    ret = ft_memalloc(sizeof(t_array));
    if (ret == NULL)
        return (NULL);
    ret->size = ARRAY_SIZE;
    ret->index = 0;
    ret->content = ft_memalloc(sizeof(void *) * ARRAY_SIZE);
    return (ret);
}

void					array_clear(t_array **array, void (*del_fct)(void **))
{
	size_t				i;
	size_t				sz;
	void				**arr;

	sz = (*array)->index;
	arr = (*array)->content;
	i = 0;
	while (i < sz)
		del_fct(arr + i++);
	free(*array);
	*array = NULL;
}
