/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaverty <aaverty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 16:42:30 by aaverty           #+#    #+#             */
/*   Updated: 2016/02/08 19:03:32 by aaverty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*printf_percent(char c, t_args args)
{
	char	*res;

	args.precision = 0;
	if (!(res = ft_strnew(1)))
		return (NULL);
	res[0] = c;
	return (res);
}
