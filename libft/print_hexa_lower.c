/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa_lower.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgutier <frgutier@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 09:30:35 by frgutier          #+#    #+#             */
/*   Updated: 2022/11/20 18:30:40 by frgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_hexa_lower(int n)
{
	int		length;

	length = 0;
	if (n >= 0)
		length = puthexa_long("0123456789abcdef", n, length);
	else if (n < 0)
		length = puthexa_uns("0123456789abcdef", n, length);
	return (length);
}
