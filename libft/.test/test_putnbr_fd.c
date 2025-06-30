/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putnbr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 10:59:32 by anemet            #+#    #+#             */
/*   Updated: 2025/06/12 11:11:09 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

// ./a.out --> display on STDOUT and STDERR and write file /tmp/fd.txt
// ./a.out > /dev/null --> display only on STDERR and write file /tmp/fd.txt
int	main(int argc, char *argv[])
{
	int	n;
	int	fd;

	if (argc < 2)
	{
		printf("usage: %s <n>\n", argv[0]);
		return (0);
	}
	n = atoi(argv[1]);
	ft_putstr_fd("STDOUT: ", 1);
	ft_putnbr_fd(n, 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("STDERR: ", 2);
	ft_putnbr_fd(n, 2);
	ft_putchar_fd('\n', 2);
	fd = open("/tmp/fd.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd >= 0)
	{
		ft_putstr_fd("FILE: ", fd);
		ft_putnbr_fd(n, fd);
		ft_putchar_fd('\n', fd);
		close(fd);
		return (0);
	}
}
