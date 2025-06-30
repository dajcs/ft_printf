/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_striteri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 11:19:48 by anemet            #+#    #+#             */
/*   Updated: 2025/06/11 11:25:09 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void	shift_x(unsigned int i, char *c)
{
	*c = ((*c + i) % 127);
}

int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("usage %s <s>\n", argv[0]);
		printf("function shift_x applied on every character of string <s>\n");
		return (1);
	}
	ft_striteri(argv[1], shift_x);
	printf("\n%s\n", argv[1]);
}
