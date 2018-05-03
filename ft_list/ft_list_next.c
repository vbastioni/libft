#include "ft_list.h"

t_list				*ft_list_next(t_list *list, t_list **prev,
									int (*assert)(void *))
{
	*prev = NULL;
	while (list != NULL)
	{
		if (assert(list->content))
			return (list);
		*prev = list;
		list = list->next;
	}
	return (NULL);
}
