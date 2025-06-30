/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstdelone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 13:37:41 by anemet            #+#    #+#             */
/*   Updated: 2025/06/13 14:22:50 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

// del - helper function - frees node's content (assuming malloc'ed string)
static void	del(void *content)
{
	free(content);
}

// print_list
// renders list as: head -> ["one"] -> ["two"] ... -> NULL
static void	print_list(t_list *lst)
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
	t_list	*mid;
	t_list	*tail;

	head = ft_lstnew(ft_strdup("one"));
	mid = ft_lstnew(ft_strdup("two"));
	tail = ft_lstnew(ft_strdup("three"));
	ft_lstadd_back(&head, mid);
	ft_lstadd_back(&head, tail);
	printf("Original list:\n");
	print_list(head);
	head->next = mid->next;
	ft_lstdelone(mid, del);
	printf("\nAfter deleting \"two\":\n");
	print_list(head);
	ft_lstclear(&head, del);
	printf("\nAfter ft_lstclear(&head, del):\n");
	print_list(head);
	return (0);
}
