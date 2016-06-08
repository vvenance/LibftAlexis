/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_ls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaverty <aaverty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 13:05:19 by aaverty           #+#    #+#             */
/*   Updated: 2016/02/08 19:02:54 by aaverty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static char	wstrcpy(char c, char **str)
{
	(*str)++;
	return (c);
}

static void	printf_c2(wchar_t chr, char **str, t_args *args)
{
	if (chr <= 0x10FFFF && args->precision >= 4)
	{
		**str = (chr >> 18) + 0xF0;
		**str = wstrcpy(((chr >> 12) & 0x3F) + 0x80, str);
		**str = wstrcpy(((chr >> 6) & 0x3F) + 0x80, str);
		**str = wstrcpy((chr & 0x3F) + 0x80, str);
		args->precision -= 4;
	}
}

static void	printf_c(wchar_t chr, char **str, t_args *args)
{
	if (chr <= 0x7F && args->precision >= 1)
	{
		**str = chr;
		args->precision--;
	}
	else if (chr <= 0x7FF && args->precision >= 2)
	{
		**str = (chr >> 6) + 0xC0;
		**str = wstrcpy((chr & 0x3F) + 0x80, str);
		args->precision -= 2;
	}
	else if (chr <= 0xFFFF && args->precision >= 3)
	{
		**str = (chr >> 12) + 0xE0;
		**str = wstrcpy(((chr >> 6) & 0x3F) + 0x80, str);
		**str = wstrcpy((chr & 0x3F) + 0x80, str);
		args->precision -= 3;
	}
	else if (chr <= 0x10FFFF && args->precision >= 4)
		printf_c2(chr, str, args);
	else
		**str = '\0';
	(*str)++;
}

char		*printf_char(char c, t_args args)
{
	char	*res;

	args.precision = 0;
	if (!(res = ft_strnew(1)))
		return (NULL);
	res[0] = c;
	res[1] = '\0';
	return (res);
}

char		*printf_ls(wchar_t *str, t_args args)
{
	char	*res;
	char	*tmp;

	if (str == NULL)
		return (ft_strdup("(null)"));
	if (args.precision == -1)
		args.precision = ft_wstrlen(str);
	if (!(res = malloc(sizeof(res) * ft_wstrlen(str) + 1)))
		return (NULL);
	tmp = res;
	while (*str)
		printf_c(*str++, &res, &args);
	return (tmp);
}
