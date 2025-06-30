/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:29:52 by anemet            #+#    #+#             */
/*   Updated: 2025/06/10 11:29:37 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	char	*s1;
	char	*s2;
	char	*str;

	if (argc < 3)
	{
		printf("usage: %s <s1> <s2>\n", argv[0]);
		printf("default: s1 = \"Hello \", s2 = \"World!\"\n");
		s1 = "Hello ";
		s2 = "World!";
	}
	else
	{
		s1 = argv[1];
		s2 = argv[2];
	}
	str = ft_strjoin(s1, s2);
	if (!str)
	{
		printf("Allocation failed\n");
		return (1);
	}
	printf("s1 + s2 = \"%s\"\n", str);
	free(str);
	return (0);
}
