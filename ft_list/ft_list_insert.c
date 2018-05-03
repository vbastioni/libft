#include "ft_list.h"

void			ft_list_insert(t_list **head, t_list **curr, t_list *elem)
{
	if (*head == NULL)
	{
		*head = elem;
		*curr = elem;
	}
	else
	{
		(*curr)->next = elem;
		*curr = (*curr)->next;
	}
}
