/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschmunk <pschmunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2024/08/26 19:17:28 by pschmunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/minishell.h"

int	main(void)
{
	char			*input;
	t_command		*cmds;
	char			*command;
	int				i;
	t_args			*cmds_copy;

	signal(SIGINT, signal_handler);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		command = NULL;
		input = readline(PROMPT);
		if (input != NULL)
		{
			cmds = parse(input);
			if (cmds->args != NULL)
				command = cmds->args->token->value;
			cmds_copy = cmds->args;
			i = 0;
			while (cmds->args != NULL)
			{
				i++;
				cmds->args = cmds->args->next;
			}
			add_history(input);
			if (command != NULL)
				execute(find_cmd_path(command), cmds_copy, i);
		}
		else
		{
			printf("exit\n");
			return (0);
		}
		free(input);
	}
	return (0);
}
