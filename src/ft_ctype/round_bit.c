#include "ft_ctype.h"

int             round_bit(int n)
{
    int         i;
    int         b;
    int         neg;

    i = 0;
    b = 0;
    if (n == 0)
        return (0);
    neg = n < 0;
    n = neg ? -n : n;
    if (n < 0)
        return (n);
    while (n != 0)
    {
        i++;
        b += (n & 1);
        n >>= 1;
    }
    n = (b == 1 ? (1 << (i - 1)) : (1 << i));
    return (neg ? -n : n);
}

long            round_bit_long(long n)
{
    long        l;
    int         b;
    int         neg;

    l = 0;
    b = 0;
    if (n == 0)
        return (0);
    neg = n < 0;
    n = neg ? -n : n;
    if (n < 0)
        return (n);
    while (n != 0)
    {
        l++;
        b += (n & 1);
        n >>= 1;
    }
    n = (b == 1 ? (1 << (l - 1)) : (1 << l));
    return (neg ? -n : n);
}
