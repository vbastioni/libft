#include "ft_ctype.h"

int             round_bit(int n)
{
    int         i;

    i = 0;
    while (n != 0)
    {
        i++;
        n >>= 1;
    }
    return (1 << i);
}

long            round_bit_long(long n)
{
    long        l;

    l = 0;
    while (n != 0)
    {
        l++;
        n >>= 1;
    }
    return (1 << l);
}
