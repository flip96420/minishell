/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadamik <aadamik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 22:18:09 by aadamik           #+#    #+#             */
/*   Updated: 2023/11/27 20:34:01 by aadamik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*reversestr(char *str, char sign)
{
	int		i;
	int		len;
	char	*revstr;

	len = ft_strlen(str);
	i = 0;
	if (sign == '-')
		len++;
	revstr = malloc(len + 1);
	if (sign == '-')
	{
		revstr[i] = '-';
		i++;
	}
	while (i < len)
	{
		revstr[i] = str[len - 1 - i];
		i++;
	}
	revstr[i] = '\0';
	return (revstr);
}

static int	get_len_of_n(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	len++;
	n /= 10;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	getsign(int n)
{
	char	sign;

	if (n < 0)
		sign = '-';
	else
		sign = '+';
	return (sign);
}

char	*getstr(char *str, int n)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		str[i] = 0 + '0';
		i++;
	}
	while (n != 0)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	char	*result;
	char	sign;

	sign = getsign(n);
	len = get_len_of_n(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	if (n < 0)
		n *= -1;
	str = getstr(str, n);
	result = reversestr(str, sign);
	free(str);
	return (result);
}

// int main()
// {
// 	char *str = ft_itoa(21474);
// 	printf("%s", str);
// 	free(str);
// 	return (0);
// }
