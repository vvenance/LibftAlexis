/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_arg2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaverty <aaverty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 12:31:12 by aaverty           #+#    #+#             */
/*   Updated: 2016/02/08 19:04:19 by aaverty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*va_arg_chr(t_args args, va_list ap)
{
	return (args.funcptr(va_arg(ap, wchar_t*), args));
}

char	*intm_va_arg_lint(t_args args, va_list ap)
{
	return (args.funcptr((intmax_t)va_arg(ap, long int), args));
}

char	*uintm_va_arg_ulint(t_args args, va_list ap)
{
	return (args.funcptr((uintmax_t)va_arg(ap, unsigned long int), args));
}

char	*va_arg_intm(t_args args, va_list ap)
{
	return (args.funcptr(va_arg(ap, intmax_t), args));
}

char	*va_arg_uintm(t_args args, va_list ap)
{
	return (args.funcptr(va_arg(ap, uintmax_t), args));
}
