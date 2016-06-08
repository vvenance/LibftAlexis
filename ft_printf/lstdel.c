/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstdel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaverty <aaverty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 10:19:29 by aaverty           #+#    #+#             */
/*   Updated: 2016/02/08 19:00:43 by aaverty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void		*lstdel(t_list **alst)
{
	while (*alst)
	{
		free((*alst)->content);
		free(*alst);
		*alst = (*alst)->next;
	}
	return (NULL);
}
