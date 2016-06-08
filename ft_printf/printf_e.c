/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_e.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaverty <aaverty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 16:14:24 by aaverty           #+#    #+#             */
/*   Updated: 2016/02/08 19:01:16 by aaverty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static char	*print_exp(char *resf, int exp)
{
	char	*res;
	int		i;

	i = 0;
	if (!(res = ft_strnew(ft_strlen(resf) + 5)))
		return (NULL);
	res = ft_strcpy(res, resf);
	free(resf);
	while (res[i])
		i++;
	res[i++] = 'e';
	if (exp < 0)
	{
		res[i++] = '-';
		exp *= -1;
	}
	else
		res[i++] = '+';
	res[i++] = exp / 10 + '0';
	exp %= 10;
	res[i++] = exp + '0';
	res[i] = '\0';
	return (res);
}

char		*printf_e(long double n, t_args args)
{
	char	*res;
	int		exp;

	exp = 0;
	if (n == 0.0 || n == -0.0)
		return (print_exp(printf_f(n, args), exp));
	while (ft_floorl(n) < 1)
	{
		n *= 10;
		exp--;
	}
	while (ft_floorl(n) >= 10)
	{
		n /= 10;
		exp++;
	}
	if (!(res = printf_f(n, args)))
		return (NULL);
	if (!(res = print_exp(res, exp)))
		return (NULL);
	return (res);
}
