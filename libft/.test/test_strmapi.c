/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strmapi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:38:22 by anemet            #+#    #+#             */
/*   Updated: 2025/06/12 09:29:12 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	shift_x(unsigned int i, char c)
{
	return ((c + i) % 127);
}

int	main(int argc, char *argv[])
{
	char	*out;

	if (argc < 2)
	{
		printf("usage %s <s>\n", argv[0]);
		printf("function shift_x applied on every character of string <s>\n");
		return (1);
	}
	out = ft_strmapi(argv[1], shift_x);
	printf("\n%s\n", out);
}
