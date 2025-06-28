/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 22:26:28 by anemet            #+#    #+#             */
/*   Updated: 2025/06/28 23:02:55 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
	uintptr_t i;

	if (argc < 3)
	{
		printf("usage: %s  <c,s,p,d,i,u,x,X>  <str>\n", argv[0]);
		return(1);
	}

	i = (uintptr_t)atoi(argv[2]);
	printf("printf:    %p\n", (void *)i);
	ft_printf("ft_printf: %p\n", (void *)i);
	return 0;
}
