/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:13:39 by anemet            #+#    #+#             */
/*   Updated: 2025/06/16 10:05:35 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	char	*res;

	if (argc < 2)
	{
		printf("usage: %s <n>\n", argv[0]);
		return (1);
	}
	res = ft_itoa(atoi(argv[1]));
	printf("res = \"%s\"\n", res);
	return (0);
}
