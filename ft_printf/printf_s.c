/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaverty <aaverty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 18:05:02 by aaverty           #+#    #+#             */
/*   Updated: 2016/02/10 19:18:33 by aaverty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*printf_s(char *s, t_args args)
{
	char	*newstr;
	int		i;

	if (s == NULL && !(ft_strchr(args.option, '0')))
		return (ft_strdup("(null)"));
	else if (s == NULL)
		return (ft_strdup("\0"));
	if (args.precision < 0)
	{
		if (!(newstr = ft_strnew(ft_strlen(s) + 1)))
			return (NULL);
	}
	else
	{
		if (!(newstr = ft_strnew(args.precision + 1)))
			return (NULL);
	}
	i = 0;
	while (s[i] && args.precision--)
	{
		newstr[i] = s[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
