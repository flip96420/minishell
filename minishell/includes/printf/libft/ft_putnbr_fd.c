/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadamik <aadamik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 23:44:13 by aadamik           #+#    #+#             */
/*   Updated: 2023/11/27 20:34:59 by aadamik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	get_sign(int n)
{
	char	sign;

	if (n < 0)
		sign = '-';
	else
		sign = '+';
	return (sign);
}

static int	get_len_of_n(int n)
{
	int	len;

	len = 0;
	len++;
	n /= 10;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int	get_pow(int base_of_pow, int exponent)
{
	int	pow_of_element;

	pow_of_element = 1;
	while (exponent > 0)
	{
		pow_of_element *= base_of_pow;
		exponent--;
	}
	return (pow_of_element);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	sign;
	int		positive_len;
	char	c;

	sign = get_sign(n);
	positive_len = get_len_of_n(n);
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (sign == '-')
	{
		write(fd, &sign, 1);
		n *= -1;
	}
	while (positive_len > 0)
	{
		c = (n / get_pow(10, positive_len - 1)) + '0';
		n = n % get_pow(10, positive_len - 1);
		write(fd, &c, 1);
		positive_len--;
	}
}

// int main ()
// {
// 	int n = 1235;

// 	ft_putnbr_fd(n, 1);
// 	return (0);
// }