/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgutier <frgutier@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 09:37:25 by frgutier          #+#    #+#             */
/*   Updated: 2022/11/20 18:30:51 by frgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_hexa_pointer(void *p)
{
	unsigned long long	pointer;
	int					length;

	length = 0;
	pointer = (unsigned long long)p;
	if (write(1, "0x", 2) != 2)
		return (-1);
	length = puthexa_long("0123456789abcdef", pointer, length);
	if (length == -1)
		return (-1);
	length += 2;
	return (length);
}
