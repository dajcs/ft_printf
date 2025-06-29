/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 07:44:35 by anemet            #+#    #+#             */
/*   Updated: 2025/06/29 23:17:28 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// the anchor function. Iterates over the format string
// va_start(args, format)  points 'args' to the first argument after 'format'
// va_end(args) closes the variadic "file handle"
int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;
	int		total_len;

	i = 0;
	total_len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
			total_len += ft_eval_format(args, format, &i);
		else
		{
			ft_putchar_fd(format[i], 1);
			total_len++;
		}
		i++;
	}
	va_end(args);
	return (total_len);
}

// evaluates the complete format specifier (flags, width, etc.)
// and calls the dispatcher. The index i is passed by reference
// to advance the main loop's counter past the format specifier
int ft_eval_format(va_list args, const char *format, int *i)
{
	t_flags flags;
	char type;

	(*i)++;
	flags = ft_init_flags();
	ft_parse_flags(&flags, format, i);
	type = format[*i];
	if (ft_strchr("cspdiuxX%", type))
		return (ft_dispatch(type, flags, args));
	return (0);
}
