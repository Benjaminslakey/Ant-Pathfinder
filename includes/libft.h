/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 12:40:20 by bslakey           #+#    #+#             */
/*   Updated: 2017/02/16 06:35:43 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdint.h>
# include <stdlib.h>
# include <strings.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdbool.h>
# include <fcntl.h>

# define WHT(x) (x == ' ' || x == '\t' || x == '\r' || x == '\v' || XWHT(x))
# define XWHT(x) (x == '\f' || x == '\n' )
# define ANUM(x) (x >= '0' && x <= '9')
# define UCASE(x) (x >= 'A' && x <= 'Z')
# define LCASE(x) (x >= 'a' && x <= 'z')
# define ALPHA(x) (UCASE(x) || LCASE(x))
# define ISIGN(x) (x == '-' || x == '+')
# define VAR3_INIT0(i, j, k) int i = 0; int j = 0; int k = 0;
# define VAR4_INIT0(w, x, y, z) int w = 0; int x = 0; int y = 0; int z = 0;
# define ERR_GUARD(x, y) if (x) return (y)
# define ERR_GUARD_VR(x) if (x) return
# define MEM_GUARD(x) if (x == NULL) return (NULL)
# define MEM_GUARD_VR(x) if (x == NULL) return

# define RED "\x1b[31m"
# define YELLOW "\x1b[33m"
# define GREEN "\x1b[32m"
# define CRESET "\x1b[0m"

# define BUFF_SIZE 32

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}					t_btree;

void				*ft_realloc(const void *src, size_t o_size, size_t n_size);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void                free_strings(char ***strings);
void                free_int_2Darr(int ***arr, int height);
size_t				ft_strlen(const char *s);
char                *ft_str_replace(char **to_replace, char *replace_with);
char				*ft_strdup(const char *s1);
char				*ft_strndup(const char *s1, size_t size);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
int                 chr_count(char *s, char c);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *b, const char *l, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
intmax_t			ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				ft_str_toupper(char *str);
void				ft_str_tolower(char *str);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char*));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(const char *s, char c);
char				*ft_itoa(int n);
int 				ft_strcspn(char *s, char *allowed);
size_t				d_strlen(char *s, int index, int delim);
size_t				dstr_strlen(char *s, int index, const char *delims);
int					w_dcount(char *words, int delim);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
t_list				*ft_lstnew(void const *content, size_t size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *l_new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_btree				*ft_btree_create_node(void *item);
void				ft_btree_apply_prefix(t_btree *root, void (*f)(void *));
void				ft_btree_apply_infix(t_btree *root, void (*f)(void *));
int					ft_is_prime(int num);
void				print_bits(unsigned char octet);
void				print_hex(int n);
int					ft_sqrt(int num);
int					ft_nbrlen(intmax_t nbr, int base);
char				*ft_append_str(char *orig, const char *to_append);
char				*ft_prepend_str(char *orig, const char *to_prepend);
int					**new_int_table(int height, int width);
int					str_inhaystack(char *needle, char **haystack);
void				delete_int_table(int height, int ***table);
int					*clone_int_array(int *arr, int arr_size);
void				copy_int_array(int **dest, int *src, int arr_size);
void				integer_quicksort(int *int_table, int left, int right);
void				swap_integers(int *a, int *b);
int					ft_str_isnum(char *str);
void				array_reverse_int(int *arr, int size);
int					get_next_line(const int fd, char **line);

#endif
