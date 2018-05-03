#include "ft_string.h"

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	u_char			*cdst;
	const u_char	*csrc;

	cdst = (u_char *)dst;
	csrc = (const u_char *)src;
	if (cdst > csrc)
	{
		cdst += len - 1;
		csrc += len - 1;
		while (len--)
			*cdst-- = *csrc--;
		return (dst);
	}
	while (len--)
		*cdst++ = *csrc++;
	return (dst);
}
