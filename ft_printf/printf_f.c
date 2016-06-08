/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaverty <aaverty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 15:33:22 by aaverty           #+#    #+#             */
/*   Updated: 2016/02/08 19:01:27 by aaverty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void			all_zero(char *flo)
{
	int		i;

	i = 0;
	while (flo[i])
		++i;
	while (i && flo[i - 1] != '-')
	{
		flo[i] = flo[i - 1];
		i--;
	}
	flo[i] = '1';
}

static void			arround_flo(char *flo)
{
	int		i;

	i = 0;
	while (flo[i + 1])
		i++;
	while (flo[i] == '9' || flo[i] == '.' || (flo[i] == '0' && i == 0))
	{
		if (flo[i] == '0')
		{
			flo[i] = '1';
			return ;
		}
		else if (flo[i] == '9')
			flo[i] = '0';
		i--;
	}
	if (i < 0)
		i++;
	if ((flo[i] == '0' && i == 0) || flo[i] == '-')
		all_zero(flo);
	else
		flo[i] += 1;
}

static long double	print_res(int precision, int tmp, char *res, long double n)
{
	int		i;

	i = 0;
	while (precision)
	{
		if (precision == tmp)
			res[i++] = '.';
		n = (n - ft_floorl(n)) * 10;
		res[i++] = ft_floorl(n) + '0';
		precision--;
	}
	return (n);
}

char				*printf_f(long double n, t_args args)
{
	char		*res;
	int			tmp;
	int			i;
	int			neg;
	long int	*p;

	p = (long int*)&n;
	p++;
	tmp = args.precision;
	i = 0;
	neg = (*p & 0x8000) ? 1 : 0;
	n = (*p & 0x8000) ? -n : n;
	while (ft_floorl(n) != 0 || args.precision == tmp)
	{
		n /= 10;
		args.precision++;
	}
	if (!(res = ft_strnew(args.precision + neg + 3)))
		return (NULL);
	if (neg)
		res[i++] = '-';
	n = print_res(args.precision, tmp, &res[i], n);
	if ((n - ft_floorl(n)) * 10 >= 5)
		arround_flo(res);
	return (res);
}
