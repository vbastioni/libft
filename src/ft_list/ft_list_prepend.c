#include "ft_list.h"

void						list_prepend(t_list **dst, t_list *src)
{
	t_list *tmp;

	while (src != NULL)
	{
		tmp = src->next;
		src->next = *dst;
		*dst = src;
		src = tmp;
	}
}
