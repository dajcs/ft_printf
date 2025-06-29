/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 17:13:46 by anemet            #+#    #+#             */
/*   Updated: 2025/06/28 18:28:52 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// recursively prints a pointer address
void	ft_put_ptr(uintptr_t num)
{
	if (num < 16)
	{
		if (num < 10)
			ft_putchar_fd('0' + num, 1);
		else
			ft_putchar_fd('a' + (num - 10), 1);
	}
	else
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
}

// calculates the length of a pointer's hex representation
int	ft_ptr_len(uintptr_t num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}
