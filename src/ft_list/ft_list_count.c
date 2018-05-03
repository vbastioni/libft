#include "ft_list.h"

size_t		ft_list_len(t_list *list)
{
	size_t	len;

	len = 0;
	while (list != NULL)
	{
		len++;
		list = list->next;
	}
	return (len);
}

size_t		ft_list_count(t_list *list, int (*assert)(void *))
{
	size_t	len;

	len = 0;
	while (list != NULL)
	{
		len += assert(list->content);
		list = list->next;
	}
	return (len);
}
