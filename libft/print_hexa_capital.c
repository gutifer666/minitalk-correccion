/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa_capital.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgutier <frgutier@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 09:22:34 by frgutier          #+#    #+#             */
/*   Updated: 2022/11/20 18:30:18 by frgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_hexa_capital(int n)
{
	int		length;

	length = 0;
	if (n >= 0)
		length = puthexa_long("0123456789ABCDEF", n, length);
	else if (n < 0)
		length = puthexa_uns("0123456789ABCDEF", n, length);
	return (length);
}
