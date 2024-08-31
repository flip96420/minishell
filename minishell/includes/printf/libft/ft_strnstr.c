/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadamik <aadamik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:59:30 by aadamik           #+#    #+#             */
/*   Updated: 2023/11/17 01:43:46 by aadamik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = -1;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[++i] != '\0' && i < len)
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			k = i;
			while (haystack[k] == needle[j] && haystack[k] != '\0' && k < len)
			{
				if (needle[j + 1] == '\0')
					return ((char *)&haystack[i]);
				k++;
				j++;
			}
		}
	}
	return (NULL);
}

// int	main ()
// {
// 	printf("%p\n%p\n", strnstr("Hello World!", "lo", 6), 
//ft_strnstr("Hello World!", "lo", 6));
// 	return (0);
// }
