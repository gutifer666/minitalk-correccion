/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgutier <frgutier@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 09:42:31 by frgutier          #+#    #+#             */
/*   Updated: 2022/11/20 18:33:19 by frgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checker(char c, va_list ap)
{
	if (c == 'c')
		return (print_char(va_arg(ap, int)));
	if (c == 's')
		return (print_string(va_arg(ap, char *)));
	if (c == 'p')
		return (print_hexa_pointer(va_arg(ap, void *)));
	if (c == 'd' || c == 'i')
		return (print_number(va_arg(ap, int)));
	if (c == 'u')
		return (print_number_unsigned(va_arg(ap, unsigned int)));
	if (c == 'x')
		return (print_hexa_lower(va_arg(ap, int)));
	if (c == 'X')
		return (print_hexa_capital(va_arg(ap, int)));
	return (0);
}

static int	write_str_percent(char c, va_list ap)
{
	int	length;

	length = 0;
	if (c != '%')
	{
		length = checker(c, ap);
		if (length == -1)
			return (-1);
		return (length);
	}
	else
	{
		if (write (1, &c, 1) != 1)
			return (-1);
		return (1);
	}
}

static	int	write_str(const char *str, va_list ap, int length)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			length = length + write_str_percent(str[i + 1], ap);
			if (length == -1)
				return (-1);
			i++;
		}
		else
		{
			if (write (1, &str[i], 1) != 1)
				return (-1);
			length++;
		}
		i++;
	}
	return (length);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		length;

	length = 0;
	va_start(ap, str);
	length = write_str(str, ap, length);
	va_end(ap);
	return (length);
}
