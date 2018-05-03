#ifndef FT_STRING_H
# define FT_STRING_H

# include <sys/types.h>

# include "ft_stdlib.h"

int			        ft_atoi(const char *str);

void                *ft_memset(void *b, int c, size_t len);
void                ft_bzero(void *b, size_t len);

size_t				ft_strlen(const char *str);

void				*ft_memmove(void *dst, const void *src, size_t len);

int                 ft_strcmp(const char *s1, const char *s2);
int		            ft_strncmp(const char *s1, const char *s2, size_t n);

char                *ft_strcpy(char *dst, const char *src);
char		        *ft_strncpy(char *dst, const char *src, size_t len);

char	            *ft_strcat(char *s1, const char *s2);
char	            *ft_strncat(char *s1, const char *s2, size_t n);

char	            *ft_strnew(size_t size);
void		        ft_strdel(char **as);

char		        *ft_strndup(const char *s1, size_t n);
char		        *ft_strdup(const char *s1);
char		        *ft_strpdup(const char *s1, const char *s2);

int				    ft_strindex(const char *str, const char c);

void			    ft_ltobuf(long long l, size_t base, u_char upper,
                                char *buf);
void			    ft_ultobuf(unsigned long long l, size_t base, u_char upper,
    							char *buf);
#endif
