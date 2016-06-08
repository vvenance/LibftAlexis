/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaverty <aaverty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 14:57:35 by aaverty           #+#    #+#             */
/*   Updated: 2016/02/08 19:00:18 by aaverty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		find_percent(char **str)
{
	if (**str == '%')
	{
		(*str)++;
		while (**str == ' ')
			(*str)++;
		if (**str == '%' || **str == '\0')
			return (0);
		else
		{
			while (**str != '%')
				(*str)--;
			(*str)++;
			return (1);
		}
	}
	else
		return (0);
}
