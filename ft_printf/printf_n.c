/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_n.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaverty <aaverty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 10:12:51 by aaverty           #+#    #+#             */
/*   Updated: 2016/02/09 11:41:41 by aaverty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include <stdio.h>

char	*printf_n(int nb, int *n, t_args args)
{
	args.precision = 0;
	if (n == NULL)
		n = (int*)sizeof(void*);
	if (n == (int*)sizeof(void*))
		ft_putstr("\nerror %n : pointeur is NULL");
	else
		*n = nb;
	return (ft_strdup(""));
}
