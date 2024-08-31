/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadamik <aadamik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:03:12 by aadamik           #+#    #+#             */
/*   Updated: 2024/04/05 19:14:22 by aadamik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	get_words_count(char *s, char delim)
{
	int	i;
	int	count_chars;
	int	count_words;

	i = 0;
	count_chars = 0;
	count_words = 0;
	while (s[i] != '\0')
	{
		if (s[i] == delim && count_chars != 0)
		{
			count_words++;
			count_chars = 0;
		}
		if (s[i] != delim)
			count_chars++;
		i++;
	}
	if (s[i] == '\0' && count_chars != 0)
		count_words++;
	return (count_words);
}

char	*get_single_word(
	char *orig_str, int which_word_to_get, char delim)
{
	int	i;
	int	char_count;
	int	word_count;
	int	start;

	i = 0;
	word_count = 0;
	char_count = 0;
	while (orig_str[i] != '\0' && which_word_to_get != word_count)
	{
		if (orig_str[i] == delim && char_count != 0)
		{
			word_count++;
			char_count = 0;
		}
		if (orig_str[i] != delim)
			char_count++;
		i++;
	}
	while (orig_str[i] != '\0' && orig_str[i] == delim)
		i++;
	start = i;
	while (orig_str[i] != '\0' && orig_str[i] != delim)
		i++;
	return (ft_substr(orig_str, start, i - start));
}

char	**get_strings(
	char *original_string, int how_many_words, char delim, char **array)
{
	int	i;

	i = 0;
	while (i < how_many_words)
	{
		array[i] = get_single_word(original_string, i, delim);
		if (!array[i])
		{
			while (i > 0)
			{
				i--;
				free(array[i]);
			}
			return (NULL);
		}
		i++;
	}
	array[i] = NULL;
	return (array);
}

char	**ft_split(char *s, char c)
{
	int		how_many_words;
	char	**array_of_strings;

	how_many_words = get_words_count(s, c);
	array_of_strings = malloc((how_many_words + 1) * sizeof(char *));
	if (!array_of_strings)
		return (NULL);
	array_of_strings = get_strings(s, how_many_words, c, array_of_strings);
	return (array_of_strings);
}

// int main()
// {
// 	char **example;

// 	example = ft_split(",a ,,,,\nnn,,,\0, a",',');
// 	for (int i = 0; example[i]; i++)
// 	{
// 		printf("string nr. %i, %s\n", i, example[i]);
// 		free (example[i]);
// 	}
// 	free (example);
// 	return (0);
// }
