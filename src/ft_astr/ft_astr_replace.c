#include "ft_astr.h"

void				ft_astr_replace(char **astr, int i, char *new_val)
{
	ft_strdel(astr + i);
	astr[i] = new_val;
}
