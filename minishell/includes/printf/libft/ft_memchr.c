/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadamik <aadamik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:54:56 by aadamik           #+#    #+#             */
/*   Updated: 2023/11/17 00:14:17 by aadamik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((char *)s)[i] == (char)c)
			return (((void *)s) + i);
		i++;
	}
	return (NULL);
}

// int main()
// {
// 	char str[] = "Hello World";
// 	char c = 'W';

// 	printf("%p\n%p\n", memchr(str, c, 10), ft_memchr(str, c, 10));
// 	return (0);
// }