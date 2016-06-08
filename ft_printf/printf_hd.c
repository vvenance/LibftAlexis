/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaverty <aaverty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 06:19:25 by aaverty           #+#    #+#             */
/*   Updated: 2016/02/08 19:01:41 by aaverty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	len_of_n(short int n, t_args args)
{
	int		len;
	int		neg;

	len = 0;
	neg = (n < 0) ? 1 : 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	else if (ft_strchr(args.option, ' ') || ft_strchr(args.option, '+'))
		len++;
	while (n >= 10)
	{
		len++;
		n = n / 10;
	}
	len++;
	len = (len - neg < args.precision) ? args.precision + neg : len;
	return (len);
}

static char	*do_printf_d(char *str, short int n, int len, t_args args)
{
	int		i;

	i = 1;
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	else if (ft_strchr(args.option, '+'))
		str[0] = '+';
	else if (ft_strchr(args.option, ' '))
		str[0] = ' ';
	while (n >= 10)
	{
		str[len - i++] = (n % 10) + 48;
		n = n / 10;
		args.precision--;
	}
	str[len - i++] = (n % 10) + 48;
	args.precision--;
	while (args.precision-- > 0)
		str[len - i++] = '0';
	return (str);
}

char		*printf_hd(short int n, t_args args)
{
	int		len;
	char	*str;

	len = len_of_n(n, args);
	if (!n && args.precision == 0)
		return (ft_strdup("\0"));
	if (n == -32768)
		return (ft_strdup("-32768"));
	str = ft_strnew(len);
	if (str)
		str = do_printf_d(str, n, len, args);
	return (str);
}
