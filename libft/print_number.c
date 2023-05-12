/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgutier <frgutier@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 09:12:10 by frgutier          #+#    #+#             */
/*   Updated: 2022/11/20 18:31:50 by frgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_min(void)
{
	if (write(1, "-2147483648", 11) != 11)
		return (-1);
	return (11);
}

int	print_number(int n)
{
	int	length;

	length = 0;
	if (n == -2147483648)
		return (int_min());
	if (n < 0 && ++length)
	{
		if (write(1, "-", 1) != 1)
			return (-1);
		n = -n;
	}
	if (n > 9)
	{
		length += print_number(n / 10);
		if (length == -1)
			return (-1);
		n = n % 10;
	}
	if (n <= 9)
	{
		if (print_char (('0' + n)) == -1)
			return (-1);
		length++;
	}
	return (length);
}
