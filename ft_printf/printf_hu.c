/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaverty <aaverty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 07:12:37 by aaverty           #+#    #+#             */
/*   Updated: 2016/02/08 19:02:31 by aaverty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	len_of_n(unsigned short int n, t_args args)
{
	int		len;

	len = 0;
	while (n >= 10)
	{
		len++;
		n = n / 10;
	}
	len++;
	len = (len < args.precision) ? args.precision : len;
	return (len);
}

static char	*do_printf_u(char *str, unsigned short int n, int len, t_args args)
{
	int		i;

	i = 1;
	str[len] = '\0';
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

char		*printf_hu(unsigned short int n, t_args args)
{
	int		len;
	char	*str;

	if (!n && args.precision == 0)
		return (ft_strdup("\0"));
	len = len_of_n(n, args);
	str = ft_strnew(len);
	if (str)
		str = do_printf_u(str, n, len, args);
	return (str);
}
