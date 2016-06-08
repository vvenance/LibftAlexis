/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_k.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaverty <aaverty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 09:08:21 by aaverty           #+#    #+#             */
/*   Updated: 2016/02/08 19:02:39 by aaverty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	print_day(char *res, uintmax_t day)
{
	if (day > 31)
		return (0);
	*res-- = day % 10 + '0';
	*res-- = day / 10 + '0';
	*res = '-';
	return (1);
}

static int	print_month(char *res, uintmax_t month)
{
	if (month > 12)
		return (0);
	*res-- = month % 10 + '0';
	*res-- = month / 10 + '0';
	*res = '-';
	return (1);
}

static int	print_year(char *res, uintmax_t year)
{
	int		i;

	i = 4;
	while (i--)
	{
		*res-- = year % 10 + '0';
		year /= 10;
	}
	return (1);
}

static char	*error(char *res)
{
	free(res);
	return (NULL);
}

char		*printf_k(uintmax_t date, t_args args)
{
	char		*res;
	int			i;

	args.precision = 0;
	if (date > 99991231 || date < 101)
		return (NULL);
	if (!(res = ft_strnew(11)))
		return (NULL);
	res[10] = '\0';
	i = 0;
	if (!(print_day(&res[9], date % 100)))
		return (error(res));
	if (!(print_month(&res[6], date / 100 % 100)))
		return (error(res));
	if (!(print_year(&res[3], date / 10000)))
		return (error(res));
	return (res);
}
