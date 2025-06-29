/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 07:44:35 by anemet            #+#    #+#             */
/*   Updated: 2025/06/28 23:20:57 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// va_start(args, str)  points 'args' to the first argument after 'str'
// va_end(args) closes the variadic "file handle"
int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		print_length;

	i = 0;
	print_length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_length += ft_formats(args, str[i + 1]);
			i++;
		}
		else
		{
			print_length += ft_print_char(str[i]);
		}
		i++;
	}
	va_end(args);
	return (print_length);
}

// handle NULL pointer print before invoking ft_print_ptr()
static int ft_handle_ptr(va_list args)
{
	uintptr_t ptr_val;

	ptr_val = va_arg(args, uintptr_t);
	if (ptr_val == 0)
		return (write(1, "(nil)", 5));
	return (ft_print_ptr(ptr_val));
}

// va_arg(args, int) -> gives the argument pointed by args as an 'int'; args++;
int	ft_formats(va_list args, const char format)
{
	int	print_length;

	print_length = 0;
	if (format == 'c')
		print_length += ft_print_char(va_arg(args, int));
	else if (format == 's')
		print_length += ft_print_str(va_arg(args, char *));
	else if (format == 'p')
		print_length += ft_handle_ptr(args);
	else if (format == 'd' || format == 'i')
		print_length += ft_print_nbr(va_arg(args, int));
	else if (format == 'u')
		print_length += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		print_length += ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		print_length += ft_print_percent();
	return (print_length);
}
