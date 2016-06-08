/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_arg4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaverty <aaverty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 06:37:04 by aaverty           #+#    #+#             */
/*   Updated: 2016/02/08 19:04:37 by aaverty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*ushint_va_arg_int(t_args args, va_list ap)
{
	if (args.convert_type == 'o' || args.convert_type == 'O')
		return (printf_ho((unsigned short int)va_arg(ap, int), args));
	else
		return (printf_hu((unsigned short int)va_arg(ap, int), args));
}

char	*va_arg_dtabchar(t_args args, va_list ap)
{
	return (args.funcptr(va_arg(ap, char**), args));
}
