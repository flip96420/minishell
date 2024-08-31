/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadamik <aadamik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 01:06:21 by aadamik           #+#    #+#             */
/*   Updated: 2023/11/28 01:25:57 by aadamik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	void	*content;

	(void)del;
	new_list = NULL;
	while (lst != NULL)
	{
		content = f(lst->content);
		ft_lstadd_back(&new_list, ft_lstnew(content));
		lst = lst->next;
	}
	return (new_list);
}
