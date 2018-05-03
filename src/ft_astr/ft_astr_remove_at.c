#include "ft_astr.h"

char			*ft_astr_remove_at(char ***astr, size_t index)
{
	size_t		len;
	char		**new_arr;
	char		*ret;

	len = ft_astr_len(*astr);
	if (index > len
		|| (new_arr = (char **)ft_memalloc(sizeof(char *) * len)) == NULL)
		return (NULL);
	ret = (*astr)[index];
	ft_astr_ncopy(new_arr, *astr, index);
	ft_astr_copy(new_arr + index, (*astr) + index + 1);
	ft_memdel((void **)astr);
	*astr = new_arr;
	return (ret);
}
