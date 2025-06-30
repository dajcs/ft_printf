/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putchar_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 11:55:55 by anemet            #+#    #+#             */
/*   Updated: 2025/06/12 09:29:00 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(void)
{
	int	fd;

	ft_putchar_fd('1', 1);
	ft_putchar_fd('2', 2);
	fd = open("/tmp/fd.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd >= 0)
	{
		ft_putchar_fd('0' + fd, fd);
		ft_putchar_fd('\n', fd);
		close(fd);
		return (0);
	}
}
