#include "ft_astr.h"

int			ft_astr_append(char ***astr, char *value)
{
	size_t	len;
	char	**ret;

	if (value == NULL)
		return (1);
	len = ft_astr_len(*astr);
	if ((ret = (char **)ft_memalloc(sizeof(char *) * (len + 2))) == NULL)
		return (0);
	if (*astr == NULL)
		*ret = value;
	else
	{
		ft_astr_copy(ret, *astr);
		ret[len] = value;
		free(*astr);
	}
	*astr = ret;
	return (1);
}
