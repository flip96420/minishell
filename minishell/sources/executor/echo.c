/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadamik <aadamik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 17:23:12 by aadamik           #+#    #+#             */
/*   Updated: 2024/08/05 17:38:09 by aadamik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void ft_echo(char **args)
{
	int i;
	int n_flag;

	i = 2;
	n_flag = 0;
	// while (args[i])
	// {
	// 	j = 0;
	// 	while (args[i][j] == 'n' || args[i][j] == '-')
	// 	{
	// 		j++;
	// 		n_flag = 1;
	// 	}
	// 	i++;
	// }
	while (args[i] && !(ft_strncmp(args[i], "-n", 2)))
	{
		n_flag = 1;
		i++;
	}
	while (args[i])
	{
		ft_putstr_fd(args[i], 1);
		if (args[i + 1])
			ft_putstr_fd(" ", 1);
		i++;
	}
	if (!n_flag)
		ft_putstr_fd("\n", 1);
}
