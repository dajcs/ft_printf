/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putstr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 09:57:30 by anemet            #+#    #+#             */
/*   Updated: 2025/06/12 10:12:34 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// ./a.out --> display on STDOUT and STDERR and write file /tmp/fd.txt
// ./a.out > /dev/null --> display only on STDERR and write file /tmp/fd.txt
int	main(void)
{
	int		fd;
	char	fdc;

	ft_putstr_fd("STDOUT: Test\n", 1);
	ft_putstr_fd("STDERR: Error\n", 2);
	fd = open("/tmp/fd.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd >= 0)
	{
		fdc = '0' + fd;
		ft_putstr_fd("FILE with fd = ", fd);
		ft_putchar_fd(fdc, fd);
		ft_putchar_fd('\n', fd);
		close(fd);
		return (0);
	}
}
