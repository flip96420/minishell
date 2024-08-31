/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadamik <aadamik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:10:55 by aadamik           #+#    #+#             */
/*   Updated: 2024/04/05 19:17:33 by aadamik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dst, char *src, int dstsize)
{
	int	i;
	int	j;

	i = 0;
	while (dst[i] != '\0' && i < dstsize)
		i++;
	j = 0;
	if (dstsize > 0)
	{
		while (src[j] != '\0' && i < dstsize - 1)
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		if (i != dstsize)
			dst[i] = '\0';
	}
	return (ft_strlen(src) + i - j);
}
