/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaverty <aaverty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 14:55:23 by aaverty           #+#    #+#             */
/*   Updated: 2016/02/08 18:59:59 by aaverty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	getnarg(va_list ap, int n, int option, t_args *args)
{
	va_list		tmp;
	int			res;

	res = 0;
	if (option == 1)
	{
		va_copy(tmp, ap);
		while (n-- > 0)
			res = va_arg(tmp, int);
		return (res);
	}
	else
	{
		if (args->size_mini < 0 && !(ft_strchr(args->option, '-')))
		{
			while (args->option[n])
				n++;
			args->option[n] = '-';
			args->size_mini *= -1;
		}
		return (1);
	}
}

static int	get_info(char **format, va_list ap, int res, int wildc)
{
	while (**format == '*' || ft_isdigit(**format))
	{
		if (**format == '*')
		{
			res = 0;
			wildc = 1;
		}
		else
			res = res * 10 + **format - '0';
		(*format)++;
	}
	if (**format == '$')
	{
		(*format)++;
		res = getnarg(ap, res, 1, 0);
	}
	else if (!res && wildc)
		res = va_arg(ap, int);
	else if (res && wildc)
		va_arg(ap, int);
	return (res);
}

static int	get_convert(t_args *args, char **format)
{
	const char	size_modifier[] = "hljzL";
	const char	converter[] = "sSpdDioOuUxXcCeEfFgGaAnbrkm%";

	while (ft_strchr(size_modifier, **format))
	{
		if (args->size_mod[0] == '\0')
			args->size_mod[0] = **format;
		else if ((args->size_mod[0] == 'l' && **format == 'l')
				|| (args->size_mod[0] == 'h' && **format == 'h'))
			args->size_mod[1] = **format;
		(*format)++;
	}
	if (ft_strchr(converter, **format))
		args->convert_type = **format;
	else
		return (0);
	(*format)++;
	return (1);
}

static int	get_argnum(char **format)
{
	int		res;

	res = 0;
	while (**format >= '0' && **format <= '9')
	{
		res = res * 10 + (**format - '0');
		(*format)++;
	}
	if (!res)
		res = -1;
	if (**format != '$')
	{
		while (**format != '%' || (**format == '%' && (*format)[1] == '\0'))
			(*format)--;
		(*format)++;
		return (-1);
	}
	else
		(*format)++;
	return (res);
}

int			check_arg(char **format, t_args *args, va_list ap)
{
	int		i;

	i = 0;
	if (!(args->arg_select = get_argnum(format)))
		return (0);
	while (**format == '-' || **format == '+' || **format == '0'
			|| **format == '#' || **format == ' ' || **format == '\'')
	{
		if (!(ft_strchr(args->option, **format)))
			args->option[i++] = **format;
		args->option[i] = '\0';
		(*format)++;
	}
	if ((args->size_mini = get_info(format, ap, 0, 0)) == -1)
		return (0);
	if (**format == '.')
	{
		(*format)++;
		if ((args->precision = get_info(format, ap, 0, 0)) == -1)
			return (0);
	}
	else
		args->precision = -1;
	getnarg(ap, 0, 2, args);
	return (get_convert(args, format));
}
