/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschmunk <pschmunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 17:26:32 by pschmunk          #+#    #+#             */
/*   Updated: 2024/08/31 20:46:11 by pschmunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	execute(char *cmd_path, t_args *cmds, int num_args)
{
	pid_t	pid;
	int		i;
	char	*args[num_args];

	if (cmd_path == NULL)
		return ;
	i = 0;
	while (cmds != NULL)
	{
		args[i] = cmds->token->value;
		cmds = cmds->next;
		i++;
	}
	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
		execv(cmd_path, args);
	else
		waitpid(pid, NULL, 0);
}

// char	*find_cmd_path(char *command)
// {
// 	int		i;
// 	int		num_dirs;
// 	char	*path;
// 	char	*full_path;
// 	char	**dirs;

// 	path = getenv("PATH");
// 	num_dirs = count_words(path, ':', DEFAULT);
// 	dirs = custom_split(path, ':', DEFAULT);
// 	i = 0;
// 	while (dirs[i])
// 	{
// 		full_path = ft_strjoin(dirs[i], "/");
// 		full_path = ft_strjoin(full_path, command);
// 		if (access(full_path, X_OK) == 0)
// 			return (full_path);
// 		i++;
// 	}
// 	return (NULL);
// }
