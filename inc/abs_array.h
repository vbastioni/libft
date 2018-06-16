#ifndef ABS_ARRAH_H
# define ABS_ARRAH_H

#include <stdlib.h>
#include "libft.h"

typedef struct s_absarr t_absarr;

struct                  s_absarr
{
    size_t              length;
    size_t              capacity;
    size_t              content_size;
    unsigned char       *content;
};

t_absarr                *absarr_with_capacity(size_t content_size,
                                                size_t capacity);
t_absarr                *absarr_new(size_t content_size);

unsigned char           *absarr_get(struct s_absarr *arr, size_t n);

unsigned char           *absarr_prepend(t_absarr *arr, unsigned char *value);
unsigned char           *absarr_append(t_absarr *arr, unsigned char *value);

int                     absarr_grow(t_absarr *arr);
int                     absarr_shift(t_absarr *arr);
int                     absarr_shiftn(t_absarr *arr, size_t n);

#endif
