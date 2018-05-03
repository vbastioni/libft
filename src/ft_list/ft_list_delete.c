#include "ft_list.h"

void			ft_list_delete(t_list **elem, void (*destructor)())
{
	t_list		*e;

	e = *elem;
	destructor(e);
	*elem = NULL;
}

void			ft_list_clear(t_list **list, void (*ptr_free)(void **))
{
	t_list		*curr;
	t_list		*tmp;

	curr = *list;
	while (curr != NULL)
	{
		tmp = curr;
		curr = curr->next;
		ptr_free(&tmp->content);
		free(tmp);
		tmp = NULL;
	}
}

int				ft_list_del_until(t_list **list, int (*assert)(void *),
										void (*ptr_free)(void **))
{
	t_list		*curr;
	t_list		*tmp;

	curr = *list;
	while (curr != NULL && assert(curr->content))
	{
		tmp = curr;
		curr = curr->next;
		ptr_free(&tmp->content);
		free(tmp);
		tmp = NULL;
	}
	*list = curr;
	return (1);
}
