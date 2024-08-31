/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschmunk <pschmunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:44:29 by pschmunk          #+#    #+#             */
/*   Updated: 2024/08/06 17:48:02 by pschmunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_env	*create_node(char *env_var)
{
	t_env	*new_node;
	
	new_node = ft_malloc(sizeof(t_env));
	if (!new_node)
	{
		write(2, "Error with allocating memory", 28);
		exit(1);
	}
	new_node->env_var = ft_strdup(env_var);
	new_node->equal_sign = ft_strchr(env_var, '=');
	if (!new_node->equal_sign)
	{
		write(2, "Error with env variable", 24);
		exit(1);
	}
	new_node->start_key = env_var;
	new_node->end_key = new_node->equal_sign - 1;
	new_node->start_value = new_node->equal_sign + 1;
	new_node->end_value = ft_strchr(env_var, '\0') - 1;
	new_node->next = NULL;
	return (new_node);
}

t_env	*built_env_list(char *envp[])
{
	t_env	*head;
	t_env	*current;
	int		i;

	if (!envp || !envp[0])
		return (NULL);
	head = create_node(envp[0]);
	current = head;
	i = 1;
	while (envp[i])
	{
		current->next = create_node(envp[i]);
		current = current->next;
		i++;
	}
	return (head);
}

void	print_env(t_env *head)
{
	t_env	*current;

	current = head;
	while (current)
	{
		printf("%s\n", current->env_var);
		current = current->next;
	}
}

void	free_env(t_env *head)
{
	t_env	*current;
	t_env	*temp;

	current = head;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp->env_var);
		free(temp);
	}
}

void add_to_env_list(t_env **env_list, const char *var)
{
    t_env *new_node = create_env_node(var);
    if (new_node)
    {
        new_node->next = *env_list;
        *env_list = new_node;
    }
}