/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_px.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:33:10 by anemet            #+#    #+#             */
/*   Updated: 2025/06/30 19:29:16 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_print_px.c -> print pointer & hexadecimal
similar logic to integer printing, but accounting for the 0x prefix pointers
*/

#include "ft_printf.h"

// pad = f.precision - len;
//		calculate z-padding from precision
// if (pad < 0) -> pad == 0;
//		precision is a MINIMUM, don't truncate
// if (f.zero && !f.minus && !f.dot)
//		Rule #1, #2, #4: '0' flag is ignored if '-' or '.' is present
//		pad = f.width - len; # 'pad' now becomes width-based zero padding
// ################# Assembly stage ###############
// if (f.minus == 0)
//		Right-alignment, (no '-'), print padding if any
// cont += ft_print_padding('0', pad); # print zero padding
// count += write(1, s, len); # print the number string itself
// if (f.minus == 1)
//		left alignment with '-', print (f.width - pad - len) trailing spaces
static int	ft_out_hex(char *s, t_flags f, int len)
{
	int	count;
	int	pad;

	count = 0;
	pad = f.precision - len;
	if (pad < 0)
		pad = 0;
	if (f.zero && !f.minus && !f.dot)
		pad = f.width - len;
	if (f.minus == 0)
		count += ft_print_padding(' ', f.width - pad - len);
	count += ft_print_padding('0', pad);
	count += write(1, s, len);
	if (f.minus == 1)
		count += ft_print_padding(' ', f.width - pad - len);
	return (count);
}

// if (flags.dot && flags.precision == 0 && n == 0)
//		Rule #3: Special case for 'printf("%.0x", 0)'
int	ft_print_hex(unsigned int n, t_flags flags, char format)
{
	int		i;
	int		len;
	char	s[12];
	char	*hex_chars;

	if (format == 'x')
		hex_chars = "0123456789abcdef";
	else
		hex_chars = "0123456789ABCDEF";
	if (flags.dot && flags.precision == 0 && n == 0)
		return (ft_print_padding(' ', flags.width));
	i = 0;
	if (n == 0)
		s[i++] = '0';
	while (n > 0)
	{
		s[i++] = hex_chars[n % 16];
		n /= 16;
	}
	len = i;
	ft_strrev(s, len);
	return (ft_out_hex(s, flags, len));
}

// Simplified pointer printing logic
// Here we just handle padding around the basic output
// For simplicity, we'll do a basic padded version
// len = ft_ptr_len(ptr) + 2; # +2 for "0x"
int	ft_print_ptr(uintptr_t ptr, t_flags flags)
{
	int		count;
	int		len;
	// char	s[20];

	count = 0;
	if (ptr == 0 && flags.dot && flags.precision == 0)
		return (ft_print_padding(' ', flags.width - 2) + write(1, "0x", 2));
	if (ptr == 0)
		return (ft_print_str("(nil)", flags));
	len = ft_ptr_len(ptr) + 2;
	if (flags.minus == 0)
		count += ft_print_padding(' ', flags.width - len);
	count += write(1, "0x", 2);
	ft_put_ptr(ptr);
	count += len - 2;
	if (flags.minus == 1)
		count += ft_print_padding(' ', flags.width - len);
	return (count);
}
