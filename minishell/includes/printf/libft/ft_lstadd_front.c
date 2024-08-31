/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadamik <aadamik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:06:26 by aadamik           #+#    #+#             */
/*   Updated: 2023/11/27 19:50:55 by aadamik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

// int main ()
// {
// 	t_list	*curr;
// 	t_list	*new;

// 	new = ft_lstnew((void*)1);
// 	curr = ft_lstnew((void*)15);
// 	ft_lstadd_front(&curr, new);

// 	printf("%d\n", (int)new->content);
// 	printf("%d\n", (int)new->next->content);
// 	return(0);
// }