/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:55:40 by anemet            #+#    #+#             */
/*   Updated: 2025/06/05 09:04:30 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memset(void *s, int c, size_t n);

int	main(void)
{
	char	buf_ft[32];
	char	buf_std[32];

	strcpy(buf_ft, "Hello, World!");
	strcpy(buf_std, "Hello, World!");
	printf("before memset:\n");
	printf("buf_ft  = \"%s\"\n", buf_ft);
	printf("buf_std = \"%s\"\n", buf_std);
	ft_memset(buf_ft + 7, '*', 5);
	memset(buf_std + 7, '*', 5);
	printf("after memset:\n");
	printf("buf_ft  = \"%s\"\n", buf_ft);
	printf("buf_std = \"%s\"\n", buf_std);
	if (memcmp(buf_ft, buf_std, 13) == 0)
		printf("ft_memset matches memset ✓\n");
	else
		printf("ft_memset does NOT match memset ✗\n");
	if (ft_memset(buf_ft, 'X', 0) == buf_ft)
		printf("len 0 leaves the buffer untouched => OK ✓\n");
	return (0);
}
