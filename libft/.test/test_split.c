/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:37:01 by anemet            #+#    #+#             */
/*   Updated: 2025/06/10 16:03:18 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_print_res(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		printf("%d.\t\"%s\"\n", i, tab[i]);
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	main(int argc, char *argv[])
{
	char	*s;
	char	c;
	char	**tab;

	if (argc < 3)
	{
		printf("usage: %s <s> <c>\n", argv[0]);
		printf("default: s = \"a, b, c\", c = \',\'\n");
		s = "a, b, c";
		c = ',';
	}
	else
	{
		s = argv[1];
		c = argv[2][0];
	}
	tab = ft_split(s, c);
	if (!tab)
	{
		printf("Allocation failed!");
		return (1);
	}
	ft_print_res(tab);
	return (0);
}
