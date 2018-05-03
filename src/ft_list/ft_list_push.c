#include "ft_list.h"

t_list				*list_push_front(t_list **head, void *content)
{
	t_list			*elem;

	if ((elem = list_create(content)) == NULL)
		return (NULL);
	elem->next = *head;
	return (*head = elem);
}

t_list				*list_push(t_list **head, t_list *elem)
{
	elem->next = *head;
	return (*head = elem);
}
