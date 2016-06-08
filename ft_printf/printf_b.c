/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaverty <aaverty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 14:45:14 by aaverty           #+#    #+#             */
/*   Updated: 2016/02/08 19:00:56 by aaverty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static uintmax_t	ft_pow(uintmax_t x, uintmax_t y)
{
	uintmax_t		res;

	res = x;
	if (!y)
		return (1);
	while (--y > 0)
		res *= x;
	return (res);
}

char				*printf_b(uintmax_t nb, t_args args)
{
	char	*res;
	int		i;

	args.precision = 0;
	i = 1;
	while (ft_pow(2, i) - 1 < nb)
		i++;
	if (!(res = malloc(sizeof(res) * (i + 1))))
		return (NULL);
	res[i] = '\0';
	i--;
	while (nb)
	{
		res[i] = '0' + nb % 2;
		nb /= 2;
		i--;
	}
	return (res);
}
