/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadamik <aadamik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:19:51 by aadamik           #+#    #+#             */
/*   Updated: 2024/04/05 18:58:31 by aadamik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*s1s2;

	s1s2 = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s1s2 == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		s1s2[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		s1s2[i] = s2[j];
		i++;
		j++;
	}
	s1s2[i] = '\0';
	return (s1s2);
}

// int main()
// {
// 	char *s1 = "qwe";
// 	char *s2 = "asd";
// 	printf("%s", ft_strjoin(s1, s2));
// 	return (0);
// }
