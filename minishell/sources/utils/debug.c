/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschmunk <pschmunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:27:06 by pschmunk          #+#    #+#             */
/*   Updated: 2024/08/26 19:47:31 by pschmunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_split(char **words)
{
	int	i;

	i = 0;
	while (words[i] != NULL)
	{
		printf("[%d] {%s}\n", i, words[i]);
		i++;
	}
}

void	print_token(t_token *token, int i)
{
	printf("Token[%d], type", i);
	if (token->type == COMMAND)
		printf("[COMMAND]");
	else if (token->type == ARG)
		printf("[ARG]");
	else if (token->type == NEWLINE_T)
		printf("[NEWLINE]");
	else if (token->type == SPACE_T)
		printf("[SPACE]");
	else if (token->type == DOLLAR)
		printf("[DOLLAR]");
	else if (token->type == PIPE)
		printf("[PIPE]");
	else if (token->type == INRED)
		printf("[INRED]");
	else if (token->type == OUTRED)
		printf("[OUTRED]");
	else if (token->type == APPEND)
		printf("[APPEND]");
	else if (token->type == HDOC)
		printf("[HDOC]");
	else if (token->type == ERROR)
		printf("[ERROR]");
	printf(",	value[%s]\n", token->value);
}

void	print_tokens(t_token *tokens)
{
	int	i;

	i = 0;
	while (tokens != NULL)
	{
		print_token(tokens, i);
		tokens = tokens->next;
		i++;
	}
}

void	print_command(t_command *cmd)
{
	int	i;
	t_args *temp1 = cmd->args;
	
	i = 0;
	printf("\nArguments:\n");
	while (temp1 != NULL)
	{
		print_token(temp1->token, i);
		temp1 = temp1->next;
		i++;
	}
	if (i == 0)
		printf("(empty)\n");
	i = 0;
	printf("\nInput Redirections:\n");
	while (cmd->inred != NULL)
	{
		print_token(cmd->inred->token, i);
		cmd->inred = cmd->inred->next;
		i++;
	}
	if (i == 0)
		printf("(empty)\n");
	i = 0;
	printf("\nOutput Redirections:\n");
	while (cmd->outred != NULL)
	{
		print_token(cmd->outred->token, i);
		cmd->outred = cmd->outred->next;
		i++;
	}
	if (i == 0)
		printf("(empty)\n");
}

void	print_commands(int num_cmds, t_command *cmds)
{
	int	i;

	i = 0;
	while (i < num_cmds)
	{
		printf("|________________| Command[%d] |________________|\n", i);
		print_command(&cmds[i]);
		printf("\n");
		i++;
	}
}

void	start_debug_mode(char **words, int num_tokens, t_token *tokens, int num_cmds, t_command *cmds)
{
	printf("\n################################ DEBUGGING CONSOLE ################################\n");
	printf("\nNUMBER OF TOKENS: %d\n", num_tokens);
	printf("\nAFTER SPLIT:\n");
	print_split(words);
	printf("\nAFTER TOKENIZING:\n");
	print_tokens(tokens);
	printf("\nAFTER ADDING COMMANDS:\n");
	print_commands(num_cmds, cmds);
	printf("###################################################################################\n\n");
}