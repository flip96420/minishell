/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschmunk <pschmunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 20:37:16 by pschmunk          #+#    #+#             */
/*   Updated: 2024/08/29 21:05:30 by pschmunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	*ft_malloc(size_t bytes, t_malloc_mode mode)
{
	void	*ptr;

	ptr = malloc(bytes);
	if (!ptr)
	{
		if (mode == EXIT)
			exit(EXIT_FAILURE);
		else if (mode == R_NULL)
			return (NULL);
	}
	return (ptr);
}

char *ft_strjoin3(char *s1,char *s2, char *s3)
{
	int len1;
	int len2;
	int len3;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	len3 = ft_strlen(s3);
	char *result = malloc(len1 + len2 + len3 + 1);
	if (!result)
		return NULL;
	ft_memcpy(result, s1, len1);
	ft_memcpy(result + len1, s2, len2);
	ft_memcpy(result + len1 + len2, s3, len3);
	result[len1 + len2 + len3] = '\0';
	return result;
}

