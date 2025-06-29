/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 12:26:29 by anemet            #+#    #+#             */
/*   Updated: 2025/06/28 15:58:18 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// prints a signed decimal number.
// Returns the number of characters printed.
int	ft_print_nbr(int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(n);
	len = ft_print_str(num);
	free(num);
	return (len);
}

// prints and unsigned decimal number
// returns the number of characters printed
int	ft_print_unsigned(unsigned int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_utoa(n);
	len = ft_print_str(num);
	free(num);
	return (len);
}

// helper to get the length of an unsigned number for ft_utoa
int	ft_num_len(unsigned int num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

// converts an unsigned int to a string
char	*ft_utoa(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_num_len(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (NULL);
	num[len] = '\0';
	len--;
	if (n == 0)
		num[0] = '0';
	while (n > 0)
	{
		num[len] = (n % 10 + '0');
		n = n / 10;
		len--;
	}
	return (num);
}
