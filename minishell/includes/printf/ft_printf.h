/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadamik <aadamik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 18:49:55 by aadamik           #+#    #+#             */
/*   Updated: 2023/12/07 15:49:27 by aadamik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "ft_printf.h"
# include "libft/libft.h"

# define DEC "0123456789"
# define HEX "0123456789abcdef"
# define HEXCAPS "0123456789ABCDEF"

int	write_posnum(unsigned long our_value, char *base_content);
int	write_num(long long our_value, char *base_content);
int	write_char(char letter);
int	write_string(char *string);
int	write_point(long pointer);
int	handle(char key, va_list args);
int	ft_printf(const char *input, ...);

#endif