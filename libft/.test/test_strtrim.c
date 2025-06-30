/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strtrim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:36:08 by anemet            #+#    #+#             */
/*   Updated: 2025/06/10 13:52:52 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	char	*out;
	char	*s1;
	char	*set;

	if (argc < 3)
	{
		printf("usage: %s <s1> <set>\n", argv[0]);
		printf("default: s1 = \" \\t\\n#abc#$\", set = \" \\t\\n$#c\"\n");
		s1 = " \t\n#abc#$";
		set = " \t\n$#c";
	}
	else
	{
		s1 = argv[1];
		set = argv[2];
	}
	out = ft_strtrim(s1, set);
	if (!out)
	{
		printf("Allocation failed!\n");
		return (1);
	}
	printf("trimmed out: \"%s\"\n", out);
	free(out);
	return (0);
}
