/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_write.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadamik <aadamik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 23:01:16 by aadamik           #+#    #+#             */
/*   Updated: 2023/12/07 15:49:25 by aadamik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	write_posnum(unsigned long our_value, char *base_content)
{
	unsigned long long	base;
	int					num_printed;

	base = ft_strlen(base_content);
	num_printed = 0;
	if (our_value >= base)
		num_printed += write_posnum(our_value / base, base_content);
	return (num_printed + write(1, &base_content[our_value % base], 1));
}

int	write_num(long long our_value, char *base_content)
{
	int	num_printed;

	num_printed = 0;
	if (our_value < 0)
	{
		num_printed += write(1, "-", 1);
		our_value *= -1;
	}
	return (num_printed + write_posnum(our_value, base_content));
}

int	write_char(char letter)
{
	return (write(1, &letter, 1));
}

int	write_string(char *string)
{
	if (string == NULL)
		return (write(1, "(null)", 6));
	return (write(1, string, ft_strlen(string)));
}

int	write_point(long pointer)
{
	int	num_printed;

	num_printed = 0;
	num_printed += write(1, "0x", 2);
	return (2 + write_posnum(pointer, HEX));
}
