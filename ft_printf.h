/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 07:15:52 by anemet            #+#    #+#             */
/*   Updated: 2025/06/30 22:40:01 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_flags
{
	int	minus;
	int	zero;
	int	width;
	int	dot;
	int	precision;
}		t_flags;

int		ft_printf(const char *format, ...);

// parsing and dispatching
int		ft_eval_format(va_list args, const char *format, int *i);
t_flags	ft_init_flags(void);
void	ft_parse_flags(t_flags *flags, const char *format, int *i);
int		ft_dispatch(char type, t_flags flags, va_list args);

// print functions for each conversion specifier
int		ft_print_char(char c, t_flags flags);
int		ft_print_str(char *str, t_flags flags);
int		ft_print_ptr(uintptr_t ptr, t_flags flags);
int		ft_print_nbr(int n, t_flags flags);
int		ft_print_unsigned(unsigned int n, t_flags flags);
int		ft_print_hex(unsigned int n, t_flags flags, char format);

// utility functions
int		ft_print_padding(char c, int len);
char	*ft_utoa(unsigned int n);
int		ft_hex_len(unsigned int n);
void	ft_put_hex(unsigned int num, const char format);
void	ft_strrev(char *s, int len);
int		ft_ptr_len(uintptr_t num);
void	ft_put_ptr(uintptr_t num);


#endif
