/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgutier <frgutier@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 08:16:26 by frgutier          #+#    #+#             */
/*   Updated: 2022/11/20 19:04:35 by frgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	puthexa_long(char *base_string, unsigned long long n, int length)
{
	unsigned long long	b;

	b = ft_strlen_f(base_string);
	if (n >= b)
	{
		length = puthexa_long(base_string, n / b, length);
		if (length == -1)
			return (-1);
		if (write (1, &base_string[n % b], 1) == -1)
			return (-1);
		length++;
	}
	else if (n < b)
	{
		if (write (1, &base_string[n], 1) == -1)
			return (-1);
		length++;
	}
	return (length);
}

int	puthexa_uns(char *base_string, unsigned int n, int length)
{
	unsigned int	b;

	b = ft_strlen_f(base_string);
	if (n >= b)
	{
		length = puthexa_uns(base_string, n / b, length);
		if (length == -1)
			return (-1);
		if (write (1, &base_string[n % b], 1) == -1)
			return (-1);
		length++;
	}
	else if (n < b)
	{
		if (write (1, &base_string[n], 1) == -1)
			return (-1);
		length++;
	}
	return (length);
}

// int	ft_strlen(char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }
