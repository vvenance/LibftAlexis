/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_arg3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaverty <aaverty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 12:31:12 by aaverty           #+#    #+#             */
/*   Updated: 2016/02/08 19:04:26 by aaverty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*ldouble_va_arg_double(t_args args, va_list ap)
{
	if (args.precision == -1 && (args.convert_type != 'a'
				&& args.convert_type != 'A'))
		args.precision = 6;
	return (args.funcptr((long double)va_arg(ap, double), args));
}

char	*va_arg_ldouble(t_args args, va_list ap)
{
	if (args.precision == -1 && (args.convert_type != 'a'
				&& args.convert_type != 'A'))
		args.precision = 6;
	return (args.funcptr((long double)va_arg(ap, double), args));
}

char	*va_arg_void(t_args args, va_list ap)
{
	return (args.funcptr(va_arg(ap, void*), args));
}

char	*uchar_va_arg_int(t_args args, va_list ap)
{
	if (args.convert_type == 'u' || args.convert_type == 'U')
		return (printf_hhu((char)va_arg(ap, int), args));
	else if (args.convert_type == 'o' || args.convert_type == 'O')
		return (printf_hho((char)va_arg(ap, int), args));
	else
		return (printf_hhx((char)va_arg(ap, int), args));
}

char	*shint_va_arg_int(t_args args, va_list ap)
{
	return (printf_hd((short int)va_arg(ap, int), args));
}
