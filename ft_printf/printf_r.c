/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_r.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaverty <aaverty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 14:54:03 by aaverty           #+#    #+#             */
/*   Updated: 2016/02/08 19:03:38 by aaverty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static char		wstrcpy(char c, char **str)
{
	(*str)++;
	return (c);
}

static void		printf_c(wchar_t chr, char **str)
{
	if (chr <= 0x7F)
		**str = chr;
	else if (chr <= 0x7FF)
	{
		**str = (chr >> 6) + 0xC0;
		**str = wstrcpy((chr & 0x3F) + 0x80, str);
	}
	else if (chr <= 0xFFFF)
	{
		**str = (chr >> 12) + 0xE0;
		**str = wstrcpy(((chr >> 6) & 0x3F) + 0x80, str);
		**str = wstrcpy((chr & 0x3F) + 0x80, str);
	}
	else if (chr <= 0x10FFFF)
	{
		**str = (chr >> 18) + 0xF0;
		**str = wstrcpy(((chr >> 12) & 0x3F) + 0x80, str);
		**str = wstrcpy(((chr >> 6) & 0x3F) + 0x80, str);
		**str = wstrcpy((chr & 0x3F) + 0x80, str);
	}
	(*str)++;
}

static void		add_spec_char(wchar_t chr, char **str)
{
	const char	spec_char[][5] = {"SOH ", "STX ", "ETX ", "EOT ", "ENQ ",
	"ACK ", "BEL ", "BS ", "HT ", "NL ", "VT ", "NP ", "CR ", "SO ", "SI ",
	"DLE ", "DC1 ", "DC2 ", "DC3 ", "DC4 ", "NAK ", "SYN ", "ETB ", "CAN ",
	"EM ", "SUB ", "ESC ", "FS ", "GS ", "RS ", "US ", "SP ", "DEL "};

	if (chr == 127)
	{
		*str = ft_strcpy(*str, spec_char[32]);
		(*str) += 4;
	}
	else
	{
		*str = ft_strcpy(*str, spec_char[chr - 1]);
		(*str) += ft_strlen(spec_char[chr - 1]);
	}
}

char			*printf_r(wchar_t *str, t_args args)
{
	char*res;
	char*tmp;

	args.precision = 0;
	if (str == NULL)
		return (ft_strdup("(NULL)"));
	if (!(res = malloc(sizeof(res) * ft_wstrlen(str) + 1)))
		return (NULL);
	tmp = res;
	while (*str)
	{
		if ((*str >= 1 && *str <= 32) || *str == 127)
			add_spec_char(*str++, &res);
		else
			printf_c(*str++, &res);
	}
	return (tmp);
}
