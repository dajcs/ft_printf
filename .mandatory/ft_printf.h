/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 07:15:52 by anemet            #+#    #+#             */
/*   Updated: 2025/06/28 12:31:54 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_formats(va_list args, const char format);

// print functions for each conversion specifier
int		ft_print_char(int c);
int		ft_print_str(char *str);
int		ft_print_ptr(uintptr_t ptr);
int		ft_print_nbr(int n);
int		ft_print_unsigned(unsigned int n);
int		ft_print_hex(unsigned int num, const char format);
int		ft_print_percent(void);

// utility functions
void	ft_put_ptr(uintptr_t num);
int		ft_ptr_len(uintptr_t num);
char	*ft_utoa(unsigned int n);
int		ft_num_len(unsigned int num);

#endif
