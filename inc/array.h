#ifndef ARRAY_H
# define ARRAY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

# include <sys/types.h>

# include "ft_stdlib.h"
# include "ft_stdio.h"

#define ARRAY_SIZE      8

typedef struct          s_array
{
    void                **content;
    size_t              size;
    size_t              index;
}                       t_array;

struct s_array          *array_new(void);
void					array_clear(t_array **array, void (*del_fct)(void **));

int                     array_cat(t_array *array, void **from);
int                     array_catn(t_array *array, void **from, size_t n);

int                     array_grown(t_array *array, size_t n);
int                     array_grow(t_array *array);

int                     array_append(t_array *array, void *from);
int						array_prepend(t_array *array, void *from);

int						array_enqueue(t_array *array, void *from);
int						array_push(t_array *array, void *from);

void					*array_dequeue(t_array *array);
void					*array_pop(t_array *array);

void					*array_remove(t_array *array, size_t pos);
int						array_insert(t_array *array, void *from, size_t pos);

void					*array_peek(t_array *array);
void					*array_first(t_array *array);
void					*array_last(t_array *array);
void					*array_front(t_array *array);
void					*array_back(t_array *array);

#endif
