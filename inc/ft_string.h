#ifndef FT_STRING_H
# define FT_STRING_H

# include <sys/types.h>

# include "ft_stdlib.h"

typedef struct s_string	t_string;

struct					s_string
{
	char				*buffer;
	size_t				used;
	size_t				size;
};

int			            ft_atoi(const char *str);

void                    *ft_memset(void *b, int c, size_t len);
void                    ft_bzero(void *b, size_t len);

size_t				    ft_strlen(const char *str);

void				    *ft_memmove(void *dst, const void *src, size_t len);

int                     ft_strcmp(const char *s1, const char *s2);
int		                ft_strncmp(const char *s1, const char *s2, size_t n);

char                    *ft_strcpy(char *dst, const char *src);
char		            *ft_strncpy(char *dst, const char *src, size_t len);

char	                *ft_strcat(char *s1, const char *s2);
char	                *ft_strncat(char *s1, const char *s2, size_t n);

char	                *ft_strnew(size_t size);
void		            ft_strdel(char **as);

char		            *ft_strndup(const char *s1, size_t n);
char		            *ft_strdup(const char *s1);
char		            *ft_strpdup(const char *s1, const char *s2);

int				        ft_strindex(const char *str, const char c);

void			        ft_ltobuf(long long l, size_t base, u_char upper,
                                    char *buf);
void			        ft_ultobuf(unsigned long long l, size_t base,
                                    u_char upper, char *buf);

t_string				*string_new(size_t first);

int						string_add(t_string *buf, char *str);
int						string_addn(t_string *buf, char *str, size_t n);
int						string_addc(t_string *buf, char c);

int						string_grow(t_string *buf);
int						string_grown(t_string *buf, size_t n);

char					*string_dump(t_string *buf);
char					*string_del(t_string **buf);
void					string_clear(t_string *buf);
void					string_nuke(t_string **buf);
void					string_printclose(t_string **buf, int fd);
int						string_addl(t_string *buf, long l);

int                     string_cmp(t_string *lhs, t_string *rhs);
int                     string_strcmp(t_string *lhs, const char *rhs);
int                     string_strncmp(t_string *lhs, const char *rhs,
                                        size_t len);

#endif
