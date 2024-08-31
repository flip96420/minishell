/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadamik <aadamik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:07:39 by aadamik           #+#    #+#             */
/*   Updated: 2023/12/07 15:58:44 by aadamik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle(char key, va_list args)
{
	if (key == 'c')
		return (write_char(va_arg(args, int)));
	if (key == 's')
		return (write_string(va_arg(args, char *)));
	if (key == 'p')
		return (write_point(va_arg(args, long)));
	if (key == 'i' || key == 'd')
		return (write_num(va_arg(args, int), DEC));
	if (key == 'u')
		return (write_posnum(va_arg(args, unsigned int), DEC));
	if (key == 'x')
		return (write_posnum(va_arg(args, unsigned int), HEX));
	if (key == 'X')
		return (write_posnum(va_arg(args, unsigned int), HEXCAPS));
	if (key == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		i;
	int		chars_printed;

	chars_printed = 0;
	va_start(args, input);
	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '%')
		{
			chars_printed += handle(input[i + 1], args);
			i++;
		}
		else
			chars_printed += write(1, &input[i], 1);
		i++;
	}
	va_end(args);
	return (chars_printed);
}

// int main()
// {
// 	// int a = -2147483;
// 	// printf("%p\n", a);
//	printf("Total chars: %i\n", ft_printf("example %c, %s\n", 'a', "string"));
//	printf("Total chars: %i\n", printf("example %c, %s\n", 'a', "string"));
// 	ft_printf("%X\n", LONG_MAX);
// 	printf("%X", LONG_MAX);
// 	return (0);
// }