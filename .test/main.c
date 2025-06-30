/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 22:26:28 by anemet            #+#    #+#             */
/*   Updated: 2025/06/30 20:29:07 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
	uintptr_t i;
	int	d;

	if (argc < 3)
	{
		printf("usage: %s  <c,s,p,d,i,u,x,X,%%>  <str>\n", argv[0]);
		return(1);
	}

	if (argv[1][0] == 'p')
	{
		i = (uintptr_t)atoi(argv[2]);
		printf("printf:    %p\n", (void *)i);
		ft_printf("ft_printf: %p\n", (void *)i);
	}
	if (argv[1][0] == 'd' || argv[1][0] == 'i')
	{
		d = atoi(argv[2]);
		printf("printf:    %d\n", d);
		ft_printf("ft_printf: %d\n", d);
	}
	return 0;
}
