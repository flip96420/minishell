/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadamik <aadamik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:58:28 by aadamik           #+#    #+#             */
/*   Updated: 2023/11/27 20:26:43 by aadamik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_lstsize(t_list *lst)
{
	t_list	*curr;
	int		i;

	i = 0;
	curr = lst;
	while (curr != NULL)
	{
		i++;
		curr = curr->next;
	}
	return (i);
}

// int main()
// {
// 	t_list	*curr;
// 	t_list	*new;
// 	t_list	*new1;

// 	new = ft_lstnew((void *)11);
// 	new1 = ft_lstnew((void *)12);
// 	ft_lstadd_front(&new1, new);
// 	curr = new;
// 	while (curr != NULL)
// 	{
// 		printf("curr = %d\n", (int)curr->content);
// 		curr = curr->next;
// 	}
// 	printf("i = %d\n", ft_lstsize(new));
// 	return (0);
// }