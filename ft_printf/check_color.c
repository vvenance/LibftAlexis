/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaverty <aaverty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 14:56:04 by aaverty           #+#    #+#             */
/*   Updated: 2016/02/08 19:00:10 by aaverty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#define COULEUR(param) ft_printf("\033[%sm",param)

static char	*ft_background_color(char *str)
{
	int		i;

	i = 0;
	if (str[i] == '<')
		while (str[i] != '>')
			i++;
	return (ft_strsub(str, 1, i - 1));
}

static char	*ft_color(char *str)
{
	int		i;

	i = 0;
	if (str[i] == '{')
		while (str[i] != '}')
			i++;
	return (ft_strsub(str, 1, i - 1));
}

int			color(char **str)
{
	int		nb;

	nb = 0;
	while (**str == '{' || **str == '<')
	{
		if (**str == '{')
			nb = check_color(str);
		if (**str == '<')
			nb = check_background_color(str);
	}
	return (nb);
}

int			check_color(char **str)
{
	const char	color[9][8] = {"black", "red", "green", "yellow", "blue",
		"magenta", "cyan", "white", "NULL"};
	int			i;
	char		*col;
	int			nb;

	nb = 0;
	i = 0;
	col = ft_color(*str);
	while (ft_strcmp(color[i], col) && i < 8)
		i++;
	if ((ft_strcmp(color[i], col)) == 0)
		COULEUR(ft_itoa(i + 30));
	if ((ft_strcmp("eoc\0", col)) == 0)
		COULEUR("0");
	else if (i >= 8)
	{
		ft_putchar('{');
		(*str) += 1;
		nb++;
		return (nb);
	}
		(*str) += (ft_strlen(col) + 2);
	return (0);
}

int			check_background_color(char **str)
{
	const char	color[9][8] = {"black", "red", "green", "yellow", "blue",
		"magenta", "cyan", "white", "NULL"};
	int			i;
	char		*col;
	int			nb;

	nb = 0;
	i = 0;
	col = ft_background_color(*str);
	while (ft_strcmp(color[i], col) && i < 8)
		i++;
	if ((ft_strcmp(color[i], col)) == 0)
		COULEUR(ft_itoa(i + 40));
	if ((ft_strcmp("eoc\0", col)) == 0)
		COULEUR("0");
	else if (i >= 8)
	{
		ft_putchar('<');
		(*str) += 1;
		nb++;
		return (nb);
	}
	(*str) += ft_strlen(col) + 2;
	return (0);
}
