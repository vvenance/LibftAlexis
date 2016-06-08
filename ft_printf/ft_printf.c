/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaverty <aaverty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 14:59:37 by aaverty           #+#    #+#             */
/*   Updated: 2016/02/09 11:41:44 by aaverty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf2.h"

static char		*print_res(va_list ap, t_args args, int i, int nb)
{
	int		j;

	j = 0;
	while (i > g_va_arg[j].i_r)
		j++;
	if (args.convert_type == 'n')
		return (printf_n(nb, (int*)va_arg(ap, void*), args));
	if (args.convert_type == 'A' || args.convert_type == 'E'
			|| args.convert_type == 'F' || args.convert_type == 'G'
			|| args.convert_type == 'X')
		return (ft_strupcase(g_va_arg[j].ft_arg(args, ap)));
	return (g_va_arg[j].ft_arg(args, ap));
}

static char		*find_func(t_args args, va_list ap, int nb)
{
	int		i;
	va_list	cpy;

	i = 0;
	while (g_tabft[i].convert_r != '\0'
			&& (g_tabft[i].convert_r != args.convert_type
				|| ft_strcmp(g_tabft[i].size_mod_r, args.size_mod)))
		i++;
	if (g_tabft[i].convert_r == '\0')
		return (NULL);
	else
		args.funcptr = g_tabft[i].ptr;
	if (args.arg_select > 0)
	{
		va_copy(cpy, ap);
		while (args.arg_select-- > 1)
			va_arg(cpy, int);
		return (print_res(cpy, args, i, nb));
	}
	else
		return (print_res(ap, args, i, nb));
}

static void		init_struct(t_args *args)
{
	int		i;

	i = 0;
	args->arg_select = 0;
	while (i < 7)
		args->option[i++] = '\0';
	args->size_mini = 0;
	args->precision = -1;
	i = 0;
	while (i < 3)
		args->size_mod[i++] = '\0';
	args->convert_type = 0;
}

static int		print(char **format, t_args *args, va_list ap, int nb)
{
	char	*res;

	if (check_arg(format, args, ap))
	{
		if (!(res = find_func(*args, ap, nb)))
			return (EOF);
		else
			nb += ft_putstr_args(res, *args);
		free(res);
	}
	else
	{
		args->convert_type = 'c';
		res = printf_char((char)**format, *args);
		nb += ft_putstr_args(res, *args);
		free(res);
		(*format)++;
	}
	return (nb);
}

int				ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	t_args		args;
	int			nb;

	nb = 0;
	va_start(ap, format);
	while (*format)
	{
		init_struct(&args);
		if (*format == '%' && find_percent((char**)&format))
			nb = print((char**)&format, &args, ap, nb);
		else if (*format == '{' || *format == '<')
			nb += color((char**)&format);
		else
		{
			ft_putchar(*format);
			if (*format)
			{
				format++;
				nb++;
			}
		}
	}
	return (nb);
}
