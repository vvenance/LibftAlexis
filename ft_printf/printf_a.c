/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaverty <aaverty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 10:17:55 by aaverty           #+#    #+#             */
/*   Updated: 2016/02/08 18:45:57 by aaverty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int		contentlstlen(t_list *lst)
{
	int		res;
	int		i;
	char	*str;

	res = 0;
	while (lst)
	{
		i = 0;
		str = lst->content;
		while (str[i])
		{
			res++;
			i++;
		}
		lst = lst->next;
	}
	return (res);
}

static char		*lsttoa(t_list **lst)
{
	char	*str;
	char	*tmp;
	int		len;
	int		i;
	int		y;

	len = contentlstlen(*lst);
	i = 0;
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (*lst)
	{
		y = 0;
		tmp = (*lst)->content;
		while (tmp[y])
			str[i++] = tmp[y++];
		free((*lst)->content);
		free(*lst);
		*lst = (*lst)->next;
	}
	free(lst);
	return (str);
}

static t_list	*creat_new_elem(long double d)
{
	char	c;

	if ((long int)d >= 10)
		c = (long int)d - 10 + 'a';
	else
		c = (long int)d + '0';
	return (ft_lstnew(&c, 1));
}

static int		convert_float(t_list **alst, long double d, size_t precision)
{
	if (!(ft_lstaddend(alst, creat_new_elem(d))))
		return (0);
	d -= (long int)d;
	if (d)
		if (!(ft_lstaddend(alst, ft_lstnew(".", 1))))
			return (0);
	while ((d * 16) - (long int)d != 0 && precision-- != 0)
	{
		d *= 16;
		if ((d - (long int)d) * 16 > 8 && !precision)
			d++;
		if (!(ft_lstaddend(alst, creat_new_elem(d))))
			return (0);
		d -= (long int)d;
	}
	if (!(ft_lstaddend(alst, ft_lstnew("p+", 2))))
		return (0);
	return (1);
}

char			*printf_a(long double d, t_args args)
{
	t_list			**alst;
	long double		pow;
	char			*tmp;

	if (!(alst = malloc(sizeof(*alst))))
		return (NULL);
	*alst = NULL;
	pow = 0.0;
	if (d < 0.0)
	{
		d *= -1;
		if (!(ft_lstaddend(alst, ft_lstnew("-", 1))))
			return (lstdel(alst));
	}
	if (!(ft_lstaddend(alst, ft_lstnew("0x", 2))))
		return (lstdel(alst));
	while (d / ft_power(2, pow) >= 2)
		pow++;
	d = d / ft_power(2, pow);
	if (!(convert_float(alst, d, args.precision)) || !(tmp = ft_itoa(pow)))
		return (lstdel(alst));
	if (!(ft_lstaddend(alst, ft_lstnew(tmp, ft_strlen(tmp)))))
		return (lstdel(alst));
	free(tmp);
	return (lsttoa(alst));
}
