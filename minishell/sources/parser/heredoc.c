/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschmunk <pschmunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:27:33 by pschmunk          #+#    #+#             */
/*   Updated: 2024/08/28 20:13:22 by pschmunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	write_tmpfile(int *fd)
{
	char	buffer[1024];
	ssize_t	n;
	FILE	*tmp_file;

	tmp_file = tmpfile();
	if (tmp_file == NULL)
	{
		perror("tmpfile");
		exit(EXIT_FAILURE);
	}
	n = 1;
	while (n > 0)
	{
		n = read(fd[0], buffer, sizeof(buffer));
		fwrite(buffer, 1, n, tmp_file);
	}
	close(fd[0]);
	rewind(tmp_file);
	fclose(tmp_file);
}

void	do_hdoc(t_token *token)
{
	int		fd[2];
	char	*input;
	char	*delimiter;

	if (pipe(fd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	delimiter = token->value + 2;
	while (1)
	{
		input = readline("> ");
		if (!input || ft_strcmp(input, delimiter) == 0)
		{
			free(input);
			break ;
		}
		write(fd[1], input, strlen(input));
		write(fd[1], "\n", 1);
		free(input);
	}
	close(fd[1]);
	write_tmpfile(fd);
}
