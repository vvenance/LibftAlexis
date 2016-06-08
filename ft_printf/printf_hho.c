/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hho.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaverty <aaverty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 05:50:55 by aaverty           #+#    #+#             */
/*   Updated: 2016/02/08 19:02:00 by aaverty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static unsigned short int	ft_pow(unsigned short int x, unsigned short int y)
{
	uintmax_t	res;

	res = x;
	if (!y)
		return (1);
	while (--y > 0)
		res *= x;
	return (res);
}

char						*printf_hho(unsigned char nb, t_args args)
{
	char		*res;
	int			i;
	const char	hexa[] = "0123456789abcdef";

	i = 1;
	if (!nb && args.precision == 0 && !(ft_strchr(args.option, '#')))
		return (ft_strdup("\0"));
	while (ft_pow(8, i) - 1 < nb)
		i++;
	i = (args.precision > i) ? args.precision : i;
	if (ft_strchr(args.option, '#') && nb)
		i++;
	if (!(res = ft_strnew(i--)))
		return (NULL);
	res[i] = (!nb) ? '0' : res[i];
	while (nb)
	{
		res[i--] = hexa[nb % 8];
		nb /= 8;
	}
	if (ft_strchr(args.option, '#') && i >= 0)
		res[i--] = '0';
	while (i >= 0)
		res[i--] = '0';
	return (res);
}
