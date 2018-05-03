#include "ft_astr.h"

void				ft_astr_foreach(char **arr, void (*act)())
{
	size_t			i;

	i = 0;
	while (arr[i] != NULL)
	{
		act(arr[i]);
		i++;
	}
}
