/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hhx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaverty <aaverty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 06:49:23 by aaverty           #+#    #+#             */
/*   Updated: 2016/02/08 19:02:16 by aaverty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	ft_pow(int x, int y)
{
	int		res;

	res = x;
	if (!y)
		return (1);
	while (--y > 0)
		res *= x;
	return (res);
}

static void	end_of_res(char *res, int i, t_args args)
{
	while ((i >= 0 && !(ft_strchr(args.option, '#'))) || (i > 1
			&& ft_strchr(args.option, '#')))
		res[i--] = '0';
	if (i > 0)
	{
		res[1] = 'x';
		res[0] = '0';
	}
}

char		*printf_hhx(unsigned char nb, t_args args)
{
	char		*res;
	int			i;
	const char	hexa[] = "0123456789abcdef";

	if (!nb && args.precision == 0)
		return (ft_strdup("\0"));
	i = 1;
	while (ft_pow(16, i) - 1 < nb)
		i++;
	i = (args.precision > i) ? args.precision : i;
	if (ft_strchr(args.option, '#') && nb)
		i += 2;
	if (!(res = malloc(sizeof(res) * (i + 1))))
		return (NULL);
	res[i] = '\0';
	i--;
	if (!nb)
		res[i] = '0';
	while (nb)
	{
		res[i--] = hexa[nb % 16];
		nb /= 16;
	}
	end_of_res(res, i, args);
	return (res);
}
