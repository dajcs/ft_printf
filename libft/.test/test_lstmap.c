/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 15:32:34 by anemet            #+#    #+#             */
/*   Updated: 2025/06/13 16:00:17 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

// free node's content - assuming malloc'ed char *
static void	del(void *content)
{
	free(content);
}

// duplicates given string and turns it to upper-case
// returns NULL on allocation failure
static void	*to_upper_dup(void *content)
{
	char	*src;
	char	*dup;
	size_t	i;

	src = (char *)content;
	dup = ft_strdup(src);
	if (!dup)
		return (NULL);
	i = 0;
	while (dup[i])
	{
		dup[i] = ft_toupper((unsigned char)dup[i]);
		i++;
	}
	return ((void *)dup);
}

// print_list
// prints list as head -> ["HELLO"] -> ["LIBFT"] -> ... -> NULL
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
	t_list	*orig;
	t_list	*copy;

	orig = NULL;
	ft_lstadd_back(&orig, ft_lstnew(ft_strdup("hello")));
	ft_lstadd_back(&orig, ft_lstnew(ft_strdup("libft")));
	ft_lstadd_back(&orig, ft_lstnew(ft_strdup("bonus")));
	printf("Original list:\n");
	print_list(orig);
	copy = ft_lstmap(orig, to_upper_dup, del);
	if (!copy)
	{
		printf("Allocation failed during ft_lstmap\n");
		ft_lstclear(&orig, del);
		return (1);
	}
	printf("\nMapped list (upper-case):\n");
	print_list(copy);
	ft_lstclear(&orig, del);
	ft_lstclear(&copy, del);
}
