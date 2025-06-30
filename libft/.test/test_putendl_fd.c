/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putendl_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 10:28:08 by anemet            #+#    #+#             */
/*   Updated: 2025/06/12 10:35:29 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// ./a.out --> display on STDOUT and STDERR and write file /tmp/fd.txt
// ./a.out > /dev/null --> display only on STDERR and write file /tmp/fd.txt
int	main(void)
{
	int		fd;
	char	fdc;

	ft_putendl_fd("STDOUT: Test", 1);
	ft_putendl_fd("STDERR: Error", 2);
	fd = open("/tmp/fd.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd >= 0)
	{
		fdc = '0' + fd;
		ft_putchar_fd(fdc, fd);
		ft_putendl_fd(" was the fd for this FILE: /tmp/fd.txt", fd);
		close(fd);
		return (0);
	}
}
