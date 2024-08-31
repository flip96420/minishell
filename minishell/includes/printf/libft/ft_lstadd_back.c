/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadamik <aadamik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 21:56:32 by aadamik           #+#    #+#             */
/*   Updated: 2023/11/27 23:15:26 by aadamik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*curr;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	curr = *lst;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->next = new;
}

// int main ()
// {
// 	t_list	*node;
// 	t_list	*new;
// 	t_list	*curr;

// 	node = malloc(sizeof(size_t));
// 	if (node == NULL)
// 		return (0);
// 	node->next = NULL;
// 	node->content = (void *)11;
// 	new = ft_lstnew((void *)12);
// 	ft_lstadd_back(&node, new);
// 	curr = node;
// 	while (curr != NULL)
// 	{
// 		printf("curr = %d\n", (int)curr->content);
// 		curr = curr->next;
// 	}

// }