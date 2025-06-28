Can you help me writing a library in `C` that contains `ft_printf()`, a function that will mimic the original `printf` from `libc`?

- prototype: `int ft_printf(const char *, ...);`
- requirements:
  - do not implement the original `printf()` buffer management
  - the function has to handle the following conversions: `cspdiuxX%`
  - the command `ar` should be used to create the library; the use of `libtool` is forbidden
  - library `libftprintf.a` must be created at the root of the repository
- conversions to implement:
  - `%c` Prints a single character.
  - `%s` Prints a string (as defined by the common C convention).
  - `%p` The void * pointer argument has to be printed in hexadecimal format.
  - `%d` Prints a decimal (base 10) number.
  - `%i` Prints an integer in base 10.
  - `%u` Prints an unsigned decimal (base 10) number.
  - `%x` Prints a number in hexadecimal (base 16) lowercase format.
  - `%X` Prints a number in hexadecimal (base 16) uppercase format.
  - `%%` Prints a percent sign.
- Allowed external functions:
  - `malloc`, `free`
  - `write`
  - `va_start`, `va_arg`, `va_copy`, `va_end`
- The Norminette rules should be adhered:
  - only while loops are allowed
  - ternary operators are not allowed
  - variable definition and variable assignment in separate rows
  - one empty line after variable definitions, no other empty lines
  - only one variable definition/assignment on a line
  - only one instruction on a single line
  - max 80 characters / line
  - max 4 parameters / function
  - max 5 variables / function
  - max 25 lines / function
  - max 5 functions / .c file
- Use of `libft` is authorized, `libft.h` below:

```h
#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

/* ---------------	LISTS		--------------- */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}		t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **alst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* ---------------	CHARS		--------------- */
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);

/* ---------------	STRINGS		--------------- */
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/* ---------------   FILE DESCRIPTORS   --------------- */
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/* ---------------	MEMORY		--------------- */
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_calloc(size_t count, size_t size);

/* ---------------	NUMBERS		--------------- */
int		ft_atoi(const char *str);
char	*ft_itoa(int n);

#endif
```