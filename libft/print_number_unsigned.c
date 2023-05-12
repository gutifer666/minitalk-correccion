/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgutier <frgutier@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 09:19:07 by frgutier          #+#    #+#             */
/*   Updated: 2022/11/20 18:31:14 by frgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	print_number_unsigned(unsigned int num)
{
	int	length;

	length = 0;
	if (num > 9)
	{
		length = print_number_unsigned(num / 10);
		if (length == -1)
			return (-1);
		num = num % 10;
	}
	if (num <= 9)
	{
		if (print_char (('0' + num)) == -1)
			return (-1);
		length++;
	}
	return (length);
}
