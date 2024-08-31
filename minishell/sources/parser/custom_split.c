/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschmunk <pschmunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:36:33 by pschmunk          #+#    #+#             */
/*   Updated: 2024/08/28 20:40:11 by pschmunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	count_words(char *str, char c, t_split_mode mode)
{
	int	i;
	int	word_num;
	int	space_num;
	int	quotes_num;

	i = 0;
	word_num = 0;
	space_num = 0;
	quotes_num = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && str[i + 1] == c && !(quotes_num % 2))
			space_num++;
		if (str[i] != c && str[i] != '"'
			&& (str[i + 1] == c || str[i + 1] == '\0') && !(quotes_num % 2))
			word_num++;
		if (str[i] == '"')
		{
			quotes_num++;
			if (!(quotes_num % 2))
			{
				space_num++;
				word_num++;
			}
		}
		i++;
	}
	if (mode == TOKEN)
		return (word_num + space_num);
	return (word_num);
}

int	word_len(char *str, int word_index, char c)
{
	int	len;

	len = 0;
	while (str[word_index] != '\0' && str[word_index] != c)
	{
		word_index++;
		len++;
	}
	return (len);
}

char	*create_word(char *str, int i, char c)
{
	int		len;
	char	*word;

	if (str[i] == ' ')
	{
		word = (char *)ft_malloc(2 * sizeof(char));
		word[0] = ' ';
		word[1] = '\0';
		return (word);
	}
	len = word_len(str, i, c);
	word = (char *)ft_malloc((len + 1) * sizeof(char));
	word[len] = '\0';
	len = 0;
	while (str[i] != '\0' && str[i] != c)
	{
		word[len] = str[i];
		len++;
		i++;
	}
	return (word);
}

char	*get_word(char *str, char c, int token_id, t_split_mode mode)
{
	int	i;
	int	token_num;
	int	count_quotes;

	i = 0;
	token_num = 0;
	count_quotes = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c && str[i - 1] != c && mode == TOKEN && !(count_quotes % 2))
			token_num++;
		if (str[i] != c && (str[i - 1] == c || i == 0)
			&& !(count_quotes % 2))
			token_num++;
		if (str[i] == '"')
			count_quotes++;
		if (token_num == token_id)
			break ;
		i++;
	}
	if (str[i] == '"')
	{
		i++;
		return (create_word(str, i, '"'));
	}
	return (create_word(str, i, c));
}

char	**custom_split(char *str, char c, t_split_mode mode)
{
	char	*null_ptr;
	char	**words;
	int		len;
	int		i;

	len = count_words(str, c, mode);
	printf("LEN: %d\n", len);
	words = (char **)ft_malloc((len + 1) * sizeof(char *));
	null_ptr = (char *)ft_malloc(1 * sizeof(char));
	null_ptr = NULL;
	words[len] = null_ptr;
	i = 0;
	while (i < len)
	{
		words[i] = get_word(str, c, i + 1, mode);
		i++;
	}
	return (words);
}
