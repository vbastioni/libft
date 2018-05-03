#include "ft_astr.h"

size_t			ft_astr_len(char **arr)
{
	size_t		len;

	if (arr == NULL)
		return (0);
	len = 0;
	while (arr[len] != NULL)
		len++;
	return (len);
}
