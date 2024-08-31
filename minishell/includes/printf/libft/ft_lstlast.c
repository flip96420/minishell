/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadamik <aadamik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 21:24:53 by aadamik           #+#    #+#             */
/*   Updated: 2023/11/27 22:30:52 by aadamik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

// int main()
// {
// 	t_list	*curr;
// 	t_list	*new;
// 	t_list	*new1;
// 	t_list	*last;

// 	new = ft_lstnew((void *)11);
// 	new1 = ft_lstnew((void *)12);
// 	ft_lstadd_front(&new1, new);
// 	curr = new;
// 	while (curr != NULL)
// 	{
// 		printf("curr = %d\n", (int)curr->content);
// 		curr = curr->next;
// 	}
// 	last = ft_lstlast(new);
// 	printf("last = %d\n", (int)last->content);
// 	return (0);
// }