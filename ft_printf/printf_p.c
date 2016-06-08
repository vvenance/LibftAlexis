/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaverty <aaverty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 14:14:06 by aaverty           #+#    #+#             */
/*   Updated: 2016/02/08 19:03:25 by aaverty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static char	*print_zero(t_args args)
{
	char	*res;
	int		i;

	if (args.precision == -1)
		args.precision = 1;
	if (!(res = ft_strnew(2 + args.precision)))
		return (NULL);
	i = 0;
	res[i++] = '0';
	res[i++] = 'x';
	while (args.precision-- > 0)
		res[i++] = '0';
	return (res);
}

char		*printf_p(void *addr, t_args args)
{
	char				*res;
	unsigned long int	n;
	int					i;
	const char			hexa[] = "0123456789abcdef";

	if (addr == 0)
		return (print_zero(args));
	n = (unsigned long int)addr;
	i = 1;
	while (ft_power(16, i) - 1 < n)
		i++;
	args.precision = (args.precision > i) ? args.precision - i : 0;
	if (!(res = ft_strnew(i + 3 + args.precision)))
		return (NULL);
	i += 1 + args.precision;
	while (n)
	{
		res[i--] = hexa[n % 16];
		n /= 16;
	}
	while (args.precision-- > 0)
		res[i--] = '0';
	res[i--] = 'x';
	res[i] = '0';
	return (res);
}
