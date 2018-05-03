#include "ft_string.h"

char		*ft_strndup(const char *s1, size_t n)
{
	char	*ret;

	if (s1 == NULL)
		return (NULL);
	if ((ret = ft_strnew(n)) == NULL)
		return (NULL);
	ft_strncpy(ret, s1, n);
	return (ret);
}

char		*ft_strdup(const char *s1)
{
	if (s1 == NULL)
		return (NULL);
	return (ft_strndup(s1, ft_strlen(s1)));
}

char		*ft_strpdup(const char *s1, const char *s2)
{
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	return (ft_strndup(s1, (size_t)(s2 - s1)));
}
