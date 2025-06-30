/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_diu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 11:35:26 by anemet            #+#    #+#             */
/*   Updated: 2025/06/30 22:39:43 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_print_diu.c -> print int & unsigned int.
interactions between `0`, `-`, `.`, `width`, `precision` and negative numbers
*/

#include "ft_printf.h"

/*
Rule 1. The - (minus) flag overrides the 0 flag. If - is present, output
		is left-aligned, and any padding is done with spaces on the right.
Rule 2. The . (precision) flag overrides the 0 flag. If precision is specified
		(e.g., %.5d), padding is done with leading zeros to meet
		the precision length, but the 0 flag is ignored for width padding.
Rule 3. Special Case %.0d and 0: If precision is 0 and the number is 0,
		nothing is printed for the number itself.
Rule 4. The 0 flag only applies if - and . are not present.
		It pads the width with leading zeros instead of spaces.
Rule 5. The width field specifies a minimum total output width.
		If the formatted number is shorter, it's padded.
		If it's longer, the width is ignored.
*/

// if (f.dot && f.precision == 0 && n == 0)
//		Rule #3: Special case for 'printf("%.0d", 0)
// pad = f.precision - len;
//		calculate z-padding from precision
// if (pad < 0) -> pad == 0;
//		precision is a MINIMUM, don't truncate
// if (n < 0) -> f.width--;
//		account for the '-' sign in the total width
// if (f.zero && !f.minus && !f.dot)
//		Rule #1, #2, #4: '0' flag is ignored if '-' or '.' is present
//		pad = f.width - len; # 'pad' now becomes width-based zero padding
// ############# Assembly stage ####################
// if (f.minus == 0)
//		Right-alignment, (no '-'), print padding if any
// if (n < 0)
//		print '-' sign if any
// cont += ft_print_padding('0', pad); # print zero padding
// count += write(1, s, len); # print the number string itself
// if (f.minus == 1)
//		left alignment with '-', print (f.width - pad - len) trailing spaces
int	ft_out_nbr(char *s, int n, t_flags f)
{
	int	count;
	int	len;
	int	pad;

	count = 0;
	len = ft_strlen(s);
	if (f.dot && f.precision == 0 && n == 0)
		len = 0;
	pad = f.precision - len;
	if (pad < 0)
		pad = 0;
	if (n < 0)
		f.width--;
	if (f.zero && !f.minus && !f.dot)
		pad = f.width - len;
	if (f.minus == 0)
		count += ft_print_padding(' ', f.width - pad - len);
	if (n < 0)
		count += write(1, "-", 1);
	count += ft_print_padding('0', pad);
	count += write(1, s, len);
	if (f.minus == 1)
		count += ft_print_padding(' ', f.width - pad - len);
	return (count);
}

int	ft_print_nbr(int n, t_flags flags)
{
	char	*s;
	int		count;
	long	nb;

	nb = n;
	if (nb < 0)
		nb = -nb;
	if (nb == 2147483648)
		s = ft_strdup("2147483648");
	else
		s = ft_itoa(nb);
	if (!s)
		return (0);
	count = ft_out_nbr(s, n, flags);
	free(s);
	return (count);
}

// reusing `ft_out_nbr(s, n, flags)` isn't perfect because
// a big unsigned `n` might be casted into negative number
// => we're using `representative_n` only to distinguish if it is 0 or not.
int	ft_print_unsigned(unsigned int n, t_flags flags)
{
	char	*s;
	int		count;
	int		representative_n;

	s = ft_utoa(n);
	if (!s)
		return (0);
	if (n == 0)
		representative_n = 0;
	else
		representative_n = 1;
	count = ft_out_nbr(s, representative_n, flags);
	free(s);
	return (count);
}
