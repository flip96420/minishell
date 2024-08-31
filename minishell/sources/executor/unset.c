/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadamik <aadamik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 20:57:57 by aadamik           #+#    #+#             */
/*   Updated: 2024/08/06 18:06:08 by aadamik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// int	ft_check_key(char *key)
// {
// 	int i;

// 	i = 0;
// 	if (!ft_isalpha(key[0]) && key[0] != '_')
// 		return (0);
// 	while (key[i] && key[i] != '=')
// 	{
// 		if (!ft_isalnum(key[i]) && key[i] != '_')
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

int ft_check_key(char *key)
{
	int i;

	printf("Debug: Checking key: %s\n", key);

	if (!key)
	{
		printf("Debug: Key is NULL\n");
		return 0;
	}

	if (*key == '\0')
	{
		printf("Debug: Key is empty\n");
		return 0;
	}

	if (!ft_isalpha(*key) && *key != '_')
	{
		printf("Debug: First character is not alphabetic or underscore: %c\n", *key);
		return 0;
	}

	i = 1;
	while (key[i])
	{
		if (!ft_isalnum(key[i]) && key[i] != '_')
		{
			printf("Debug: Invalid character in key: %c\n", key[i]);
			return 0;
		}
		i++;
	}

	printf("Debug: Key is valid\n");
	return 1;
}

void	ft_unsetenv(t_env **env_list, char *key)
{
	t_env *current = *env_list;
	t_env *prev = NULL;

	while (current)
	{
		size_t key_len = current->end_key - current->start_key + 1;
		if (ft_strncmp(current->start_key, key, key_len) == 0 && key[key_len] == '\0')
		{
			if (prev)
				prev->next = current->next;
			else
				*env_list = current->next;
			free(current->env_var);
			free(current);
			return;
		}
		prev = current;
		current = current->next;
	}
}

int	ft_unset(t_env **env_list, char **args)
{
	int i;
	int exit_status;

	i = 1;
	exit_status = 0;
	if (!args[1])
		return (0);
	while (args[i])
	{
		if (!ft_check_key(args[i]))
		{
			ft_putstr_fd("minishell: unset: `", 2);
			ft_putstr_fd(args[i], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			exit_status = 1;
		}
		else
			ft_unsetenv(env_list, args[i]);
		i++;
	}
	return (exit_status);
}
