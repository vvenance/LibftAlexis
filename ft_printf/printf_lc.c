/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_lc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaverty <aaverty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 14:47:18 by aaverty           #+#    #+#             */
/*   Updated: 2016/02/08 19:02:46 by aaverty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void	print_lc(char *res, wint_t chr)
{
	res[0] = (chr >> 18) + 0xF0;
	res[1] = ((chr >> 12) & 0x3F) + 0x80;
	res[2] = ((chr >> 6) & 0x3F) + 0x80;
	res[3] = (chr & 0x3F) + 0x80;
}

char		*printf_lc(wint_t chr, t_args args)
{
	char	*res;
	int		i;

	args.precision = 0;
	i = 0;
	if (!chr)
		return (ft_strdup("\0"));
	if (!(res = ft_strnew(5)))
		return (NULL);
	if (chr <= 0x7F)
		res[0] = chr;
	else if (chr <= 0x7FF)
	{
		res[0] = (chr >> 6) + 0xC0;
		res[1] = (chr & 0x3F) + 0x80;
	}
	else if (chr <= 0xFFFF)
	{
		res[0] = (chr >> 12) + 0xE0;
		res[1] = ((chr >> 6) & 0x3F) + 0x80;
		res[2] = (chr & 0x3F) + 0x80;
	}
	else if (chr <= 0x10FFFF)
		print_lc(res, chr);
	return (res);
}
