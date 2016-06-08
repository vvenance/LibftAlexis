/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_g.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaverty <aaverty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 12:24:34 by aaverty           #+#    #+#             */
/*   Updated: 2016/02/08 19:01:34 by aaverty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void		delete_zero(char *res)
{
	int		i;
	int		dot;

	i = 0;
	while (res[i + 1] && res[i + 1] != 'e')
	{
		dot = (res[i] == '.') ? 1 : dot;
		i++;
	}
	if (dot)
		while (res[i] == '0')
		{
			if (res[i + 1] == '\0')
				res[i] = '\0';
			else
			{
				dot = i;
				while (res[dot])
				{
					res[dot] = res[dot + 1];
					dot++;
				}
			}
			i--;
		}
}

static size_t	find_exp(long double n)
{
	size_t	res;

	res = 0;
	while (ft_floorl(n) < 1)
	{
		n *= 10;
		res--;
	}
	while (ft_floorl(n) >= 10)
	{
		n /= 10;
		res++;
	}
	return (res);
}

char			*printf_g(long double n, t_args args)
{
	char	*res;
	int		exp;

	exp = find_exp(n);
	args.precision = (args.precision == 0) ? 1 : args.precision;
	if (exp > -4 || exp < args.precision)
	{
		args.precision = args.precision - exp - 1;
		if (!(res = printf_f(n, args)))
			return (NULL);
	}
	else
	{
		args.precision -= 1;
		if (!(res = printf_e(n, args)))
			return (NULL);
	}
	delete_zero(res);
	return (res);
}
