/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschmunk <pschmunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:07:03 by pschmunk          #+#    #+#             */
/*   Updated: 2024/08/31 19:42:13 by pschmunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token	*lstnew_token(void *content, t_token_type type)
{
	t_token	*new_node;

	new_node = ft_malloc(sizeof(t_token), R_NULL);
	new_node->value = content;
	new_node->type = type;
	new_node->next = NULL;
	return (new_node);
}

t_args	*lstnew_args(void *content)
{
	t_args	*new_node;

	new_node = malloc(sizeof(t_args));
	if (new_node == NULL)
		return (NULL);
	new_node->token = content;
	new_node->next = NULL;
	return (new_node);
}

t_inred	*lstnew_inred(void *content)
{
	t_inred	*new_node;

	new_node = malloc(sizeof(t_inred));
	if (new_node == NULL)
		return (NULL);
	new_node->token = content;
	new_node->next = NULL;
	return (new_node);
}

t_outred	*lstnew_outred(void *content)
{
	t_outred	*new_node;

	new_node = malloc(sizeof(t_outred));
	if (new_node == NULL)
		return (NULL);
	new_node->token = content;
	new_node->next = NULL;
	return (new_node);
}
