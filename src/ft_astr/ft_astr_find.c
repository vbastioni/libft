#include "ft_astr.h"

char			*ft_astr_find(char **astr, char *str)
{
	if (astr == NULL || str == NULL)
		return (NULL);
	while (*astr != NULL)
	{
		if (ft_strcmp(*astr, str) == 0)
			return (*astr);
		astr++;
	}
	return (NULL);
}

char			*ft_astr_findn(char **astr, char *str, size_t n)
{
	if (astr == NULL || str == NULL)
		return (NULL);
	while (*astr != NULL)
	{
		if (ft_strncmp(*astr, str, n) == 0)
			return (*astr);
		astr++;
	}
	return (NULL);
}

char			*ft_astr_findpart(char **astr, char *str,
									char *(*mapper)(char *))
{
	char		*tmp;

	if (astr == NULL || str == NULL || mapper == NULL)
		return (NULL);
	if ((tmp = ft_astr_find(astr, str)) != NULL)
		return (mapper(tmp));
	return (NULL);
}
