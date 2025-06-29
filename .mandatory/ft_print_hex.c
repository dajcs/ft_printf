/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 16:02:20 by anemet            #+#    #+#             */
/*   Updated: 2025/06/28 17:11:13 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// helper for ft_print_hex
// recursively prints a number in hexadecimal format
void	ft_put_hex(unsigned int num, const char format)
{
	if (num < 16)
	{
		if (num < 10)
			ft_putchar_fd(('0' + num), 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd('a' + (num - 10), 1);
			if (format == 'X')
				ft_putchar_fd('A' + (num - 10), 1);
		}
	}
	else
	{
		ft_put_hex(num / 16, format);
		ft_put_hex(num % 16, format);
	}
}

// calculates the length of a number when printed in hex
int	ft_hex_len(unsigned int num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

// prints a number in hex (lowercase or uppercase)
// returns the number of characters printed
int	ft_print_hex(unsigned int num, const char format)
{
	if (num == 0)
		return (write(1, "0", 1));
	ft_put_hex(num, format);
	return (ft_hex_len(num));
}

// prints a pointer address in hexadecimal.
// returns the number of characters printed
int	ft_print_ptr(uintptr_t ptr)
{
	int	print_length;

	print_length = 0;
	print_length += write(1, "0x", 2);
	if (ptr == 0)
		print_length += write(1, "0", 1);
	else
	{
		ft_put_ptr(ptr);
		print_length += ft_ptr_len(ptr);
	}
	return (print_length);
}
