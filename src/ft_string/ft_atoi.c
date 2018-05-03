#include "ft_string.h"
//#include "ft_ctype.h"

static int  ft_isspace(int c)
{
    if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
        || c == '\r')
        return (1);
    return (0);
}

int			ft_atoi(const char *str)
{
    int sign;
    int nb;

    sign = 1;
    nb = 0;
    while (ft_isspace(*str))
        str++;
    if (*str == '-')
        sign = -1;
    if (*str == '-' || *str == '+')
        str++;
    while (*str >= '0' && *str <= '9')
        nb = (nb * 10) + *str++ - '0';
    return (sign * nb);
}
