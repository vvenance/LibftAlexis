/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaverty <aaverty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 12:51:22 by aaverty           #+#    #+#             */
/*   Updated: 2016/02/08 19:00:34 by aaverty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void	ft_putargs_sc(char *s, t_args args, int *res, int *res2)
{
	if (*s == '-' || *s == '+' || *s == ' ')
	{
		*res2 -= 1;
		write(1, s++, 1);
	}
	if (s[0] == '0' && s[1] == 'x')
	{
		*res2 -= 2;
		s += write(1, s, 2);
	}
	while (args.size_mini-- > 0)
		*res += write(1, "0", 1);
	write(1, s, *res2);
}

static void	ft_putspace(char *s, t_args args, int *res, int *res2)
{
	while (args.size_mini-- > 0)
		*res += write(1, " ", 1);
	write(1, s, *res2);
}

static void	ft_putspace2(char *s, t_args args, int *res, int *res2)
{
	write(1, s, *res2);
	while (args.size_mini-- > 0)
		*res += write(1, " ", 1);
}

int			ft_putstr_args(char *s, t_args args)
{
	int		res;
	int		res2;

	res = 0;
	if (s == NULL)
	{
		ft_putstr_args("(null)", args);
		return (6);
	}
	if (*s == '\0' && (args.convert_type == 'c' || args.convert_type == 'C'))
		res++;
	res += ft_strlen(s);
	args.size_mini -= res;
	res2 = res;
	if (ft_strchr(args.option, '-'))
		ft_putspace2(s, args, &res, &res2);
	else if (ft_strchr(args.option, '0') && (args.precision <= -1
				|| args.convert_type == 'c' || args.convert_type == 's'
				|| args.convert_type == '%' || args.convert_type == 'S'))
		ft_putargs_sc(s, args, &res, &res2);
	else
		ft_putspace(s, args, &res, &res2);
	return (res);
}
