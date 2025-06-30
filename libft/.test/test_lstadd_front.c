/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstadd_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:29:55 by anemet            #+#    #+#             */
/*   Updated: 2025/06/13 15:47:16 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	print_list(t_list *lst)
{
	t_list	*cur;

	cur = lst;
	printf("head ");
	fflush(stdout);
	while (cur)
	{
		printf("-> [\"%s\"] ", (char *)cur->content);
		fflush(stdout);
		cur = cur->next;
	}
	printf("-> NULL\n");
}

int	main(void)
{
	t_list	*head;
	t_list	*node;

	head = NULL;
	printf("Initial list:\n");
	print_list(head);
	node = ft_lstnew("one");
	ft_lstadd_front(&head, node);
	printf("\nAfter adding \"one\" at front:\n");
	print_list(head);
	node = ft_lstnew("two");
	ft_lstadd_front(&head, node);
	printf("\nAfter adding \"two\" at front:\n");
	print_list(head);
	node = ft_lstnew("three");
	ft_lstadd_front(&head, node);
	printf("\nAfter adding \"three\" at front:\n");
	print_list(head);
}
