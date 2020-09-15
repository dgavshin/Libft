/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:43:19 by acyrenna          #+#    #+#             */
/*   Updated: 2020/09/15 11:20:32 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "ft_printf.h"

# define BUFF_SIZE 1024

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				*ft_memcpy(void *restrict dest,
							const void *restrict src, size_t n);
void				*ft_memrcpy(void *dest, const void *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putnbr(int nbr);
void				*ft_memalloc(size_t size);
void				*ft_memalloc(size_t size);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putendl(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putchar_fd(char c, int fd);
void				*ft_memccpy(void *dst, const void *src, int c, size_t len);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				ft_strdel(char **as);
void				*ft_realloc(void *ptr, size_t size);
void				ft_memdel(void **ap);
int					ft_chrcmp(char c1, char c2);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
long				ft_atol(char *str, int *errno);
int					ft_atoi(const char *str);
int					ft_atoi_base(const char *str, size_t base);
int					ft_strequ(char const *s1, char const *s2);
int					ft_isprint(int c);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_abs(int nbr);
int					ft_min(int a, int b);
int					ft_isspace(int c);
int					ft_isupper(int c);
int					ft_strndigc(const char *str, size_t max);
int					*ft_range(int min, int max);
int					word_count(const char *str, char c);

char				*ft_strdup(const char *s1);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strtrim(char const *s);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strcat(char *restrict s1, const char *restrict s2);
char				*ft_strncat(char *restrict s1,
						const char *restrict s2, size_t n);
void				ft_strrev(char *str, int len);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnchr(const char *s, int c, int len);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strstr(const char *str, const char *to_find);
char				*ft_strnstr(const char *str, const char *tofind, size_t n);
char				*ft_strnew(size_t size);

size_t				ft_power(int n, int p);
size_t				ft_strisize(int n);
size_t				ft_strlcat(char *restrict dest,
						const char *restrict src, size_t size);
size_t				ft_strlen(const char *str);
size_t				ft_strnlen(const char *str, size_t maxlen);

t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstcreate(t_list *list, void const *cont, size_t size);
t_list				*ft_lstlast(t_list *list);
t_list				*ft_lstfirst(t_list *list);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

int					get_next_line(const int fd, char **line);
int					ft_printf(const char *format, ...);
#endif
