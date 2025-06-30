/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_substr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:29:52 by anemet            #+#    #+#             */
/*   Updated: 2025/06/06 15:30:13 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	char			*str;
	unsigned int	start;
	size_t			len;
	char			*sub;

	if (argc < 4)
	{
		printf("usage: %s <string> <start> <len>\n", argv[0]);
		return (1);
	}
	str = argv[1];
	start = (unsigned int)ft_atoi(argv[2]);
	len = (size_t)ft_atoi(argv[3]);
	sub = ft_substr(str, start, len);
	if (!sub)
	{
		printf("Allocation failed\n");
		return (1);
	}
	printf("Original : \"%s\"\n", str);
	printf("Substring: \"%s\"\n", sub);
	free(sub);
	return (0);
}
