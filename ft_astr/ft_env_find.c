#include "ft_astr.h"

char				*ft_env_find(char **env, char *key)
{
	size_t			len;

	if (env == NULL || key == NULL)
		return (NULL);
	len = ft_strlen(key);
	while (*env != NULL)
	{
		if (ft_strncmp(*env, key, len) == 0 && (*env)[len] == '=')
			return ((*env) + len + 1);
		env++;
	}
	return (NULL);
}
