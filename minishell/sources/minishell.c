/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschmunk <pschmunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2024/08/31 20:23:05 by pschmunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/minishell.h"

int	main(int ac, char **av, char **env)
{
	int			i;
	char		*input;
	char		*command;
	t_command	*cmds;
	t_env		*env_list;
	t_args		*cmds_copy;

	(void)ac;
	(void)av;
	env_list = built_env_list(env);
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
				forking(cmds, (cmds->pipe_num + 1));
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
