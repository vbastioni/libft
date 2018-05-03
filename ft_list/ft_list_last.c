#include "ft_list.h"

t_list			*ft_list_last(t_list *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next != NULL)
		list = list->next;
	return (list);
}
