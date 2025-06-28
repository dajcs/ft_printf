/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_primitives.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 11:40:27 by anemet            #+#    #+#             */
/*   Updated: 2025/06/28 11:45:07 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// prints a single character, and returns 1
int ft_print_char(int c)
{
	write(1, &c, 1);
	return 1;
}

// prints a string. Handles NULL by printing "(null)".
// Returns the number of characters printed.
int ft_print_str(char *str)
{
	int i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return 6;
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return i;
}

// prints the '%' character and returns 1
int ft_print_percent(void)
{
	write(1, "%", 1);
	return 1;
}

