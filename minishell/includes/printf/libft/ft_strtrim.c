/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadamik <aadamik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:00:00 by aadamik           #+#    #+#             */
/*   Updated: 2024/04/05 19:19:12 by aadamik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

int	setins(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

int	find_front(char *s1, char *set)
{
	int	front;

	front = 0;
	while (setins(s1[front], set))
		front ++;
	return (front);
}

int	find_back(char *s1, char *set, int len)
{
	int	back;
	int	i;

	back = 0;
	i = len - 1;
	while (i >= 0 && setins(s1[i], set))
	{
		i--;
		back++;
	}
	return (back);
}

char	*cpy_trimm_str(char *s1, int front, int trimmedlen)
{
	char	*strimmed;
	int		i;
	int		j;

	strimmed = malloc(trimmedlen + 1);
	if (!strimmed)
		return (NULL);
	i = front;
	j = 0;
	while (j < trimmedlen)
	{
		strimmed[j] = s1[i];
		i++;
		j++;
	}
	strimmed[j] = '\0';
	return (strimmed);
}

char	*ft_strtrim(char *s1, char *set)
{
	int		len;
	int		front;
	int		back;
	int		trimmedlen;

	if (!s1 || !set)
		return (NULL);
	front = find_front(s1, set);
	len = ft_strlen(s1);
	back = find_back(s1, set, len);
	trimmedlen = len - front - back;
	if (trimmedlen < 0)
		trimmedlen = 0;
	return (cpy_trimm_str(s1, front, trimmedlen));
}

// int main()
// {
//     char *trimmed = ft_strtrim("", "");
//     if (trimmed)
//     {
//         printf("%s\n", trimmed);
//         free(trimmed);
//     }
//     else
//     {
//         printf("Memory allocation failed.\n");
//     }
//     return 0;
// }
