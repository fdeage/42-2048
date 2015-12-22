/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:02:02 by fdeage            #+#    #+#             */
/*   Updated: 2015/03/01 23:05:39 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include "gnl.h"
# include "macros.h"

/*
** ft_memset.c
*/

void		*ft_memset(void *str, int chr, size_t n);
void		ft_bzero(void *str, size_t n);

/*
** ft_memcpy.c
*/

void		*ft_memcpy(void *s1, const void *s2, size_t n);
void		*ft_memccpy(void *s1, const void *s2, int c, size_t n);

/*
** ft_mem_misc.c
*/

void		*ft_memmove(void *s1, const void *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		ft_memdel(void **ap);

/*
** ft_map_iter.c
*/

void		ft_striter(char *s, void (*f)(char *));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strmap(char const *s, char (*f)(char));
char		*ft_strmapi(char const *s, char(*f)(unsigned int, char));

/*
** ft_str...
*/

char		*ft_strnew(size_t size);
void		ft_strdel(char **as);
void		ft_strclr(char *s);
int			ft_strequ(char const *s1, char const *s2);
int			ft_strnequ(char const *s1, char const *s2, size_t n);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		*ft_strtrim(char const *s);
char		**ft_strsplit(char const *s, char c);
char		**ft_strsplit_str(char const *s1, char const *s2);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strrev(char *s);
char		*ft_getfirststr(const char *s1);
size_t		ft_strlen(const char *str);
size_t		ft_strpos(const char *str, int c);

/*
** ft_strcpy.c / ft_strdup.c
*/

char		*ft_strncpy(char *str1, const char *str2, size_t len);
char		*ft_strcpy(char *str1, const char *str2);
char		*ft_strdup(const char *s1);

/*
** ft_strcat.c
*/

char		*ft_strcat(char *s1, const char *s2);
char		*ft_strncat(char *s1, const char *s2, size_t n);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
char		*ft_strjoin(char const *s1, char const *s2);

/*
** ft_strchr.c
*/

char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);

/*
** ft_strchr.c
*/

char		*ft_strstr(const char *s1, const char *s2);
char		*ft_strnstr(const char *s1, const char *s2, size_t n);

/*
** ft_print.c / ft_print_fd.c
*/

void		ft_putchar(char c);
void		ft_putstr(char const *s);
void		ft_putendl(char const *s);
void		ft_putnbr(int n);
void		ft_puttab(char const **ss);

void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char const *s, int fd);
void		ft_putendl_fd(char const *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_puttab_fd(char const **ss, int fd);

void		ft_printchar_hex_fd(unsigned char n, int fd, int *print_all);
void		ft_printhex(uint32_t n, int print_all);
void		ft_printhex_fd(uint32_t n, int fd, int print_all);

/*
** ft_color.c
*/

void		ft_putstr_color(char const *s, char const *color);
void		ft_putstr_color_fd(char const *s, char const *color, int fd);
void		ft_color_switch_fd(char const *color, int fd);
void		ft_color_reset_fd(int fd);

/*
** ft_error.c
*/

t_error		*err1(t_error *error, const char *file, const char *func, int line);
t_error		*err2(char *msg1, char *msg2, t_err_status status);
int			ft_err_i(t_error *err, int ret_value, int fd);
void		*ft_err_p(t_error *err, void *ret_value, int fd);

/*
** ft_minmax.c
*/

size_t		ft_min(size_t a, size_t b);
size_t		ft_max(size_t a, size_t b);
float		ft_min_float(float a, float b);
float		ft_max_float(float a, float b);

/*
** ft_is.c / ft_to.c
*/

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);

int			ft_isspace(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);

int			ft_isnumeric(const char *s);
int			ft_aredigits(const char *s);

/*
** ft_list1.c
*/

t_list		*ft_lstnew(void const *content, size_t content_size);
void		ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void		ft_lstdel(t_list **alst, void (*del)(void *, size_t));

/*
** ft_list2.c
*/

void		ft_lstadd(t_list **alst, t_list *new);
void		ft_lstadd_back(t_list **root, t_list *new);
void		ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** misc
*/

size_t		pow_a(int a, int b);
void		*ft_memalloc(size_t size);
void		*ft_calloc(size_t size);
void		*ft_realloc(void *ptr, size_t size);

int			ft_atoi(const char *str);
char		*ft_itoa(int n);
char		*ft_itoatab(int nbr, char *tab);

void		ft_qsort(int tab[], int beg, int end);
void		ft_swap(void **p1, void **p2);

#endif
