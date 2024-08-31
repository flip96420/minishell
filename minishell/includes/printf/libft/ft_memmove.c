/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadamik <aadamik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:17:35 by aadamik           #+#    #+#             */
/*   Updated: 2023/11/27 20:36:43 by aadamik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	int	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	if (dest > src)
	{
		i = ((int)len - 1);
		while (i >= 0)
		{
			*((char *)dest + i) = *((char *)src + i);
			i--;
		}
	}
	else
	{
		while (i < (int)len)
		{
			*((char *)dest + i) = *((char *)src + i);
			i++;
		}
	}
	return (dest);
}
