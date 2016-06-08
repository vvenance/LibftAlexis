/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_arg1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaverty <aaverty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 12:31:12 by aaverty           #+#    #+#             */
/*   Updated: 2016/02/08 19:04:12 by aaverty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*intm_va_arg_int(t_args args, va_list ap)
{
	char	*res;

	if (!(res = args.funcptr((intmax_t)va_arg(ap, int), args)))
		return (NULL);
	return (res);
}

char	*uintm_va_arg_uint(t_args args, va_list ap)
{
	return (args.funcptr((uintmax_t)va_arg(ap, unsigned int), args));
}

char	*va_arg_str(t_args args, va_list ap)
{
	return (args.funcptr(va_arg(ap, char*), args));
}

char	*char_va_arg_int(t_args args, va_list ap)
{
	args.funcptr = (void*)args.funcptr;
	if (args.convert_type == '%')
		return (printf_percent('%', args));
	else if (args.convert_type == 'c')
		return (printf_char((char)va_arg(ap, int), args));
	else
		return (printf_hhd((char)va_arg(ap, int), args));
}

char	*wint_va_arg_int(t_args args, va_list ap)
{
	return (args.funcptr((wint_t)va_arg(ap, int), args));
}
