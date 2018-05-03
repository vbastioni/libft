#include "ft_list.h"

t_list				*list_create(void *content)
{
	t_list			*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}
