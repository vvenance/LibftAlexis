/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaverty <aaverty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:11:58 by aaverty           #+#    #+#             */
/*   Updated: 2016/02/09 11:27:21 by aaverty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF2_H
# define FT_PRINTF2_H

# include "ft_printf.h"

t_tabft			g_tabft[] =
{
	{"hh", 'd', &printf_d}, {"hh", 'i', &printf_d},
	{"", 'c', &printf_ls}, {"", '%', &printf_ls},

	{"hh", 'o', &printf_o}, {"hh", 'u', &printf_u},
	{"hh", 'x', &printf_x}, {"hh", 'X', &printf_x},

	{"h", 'd', &printf_d}, {"h", 'i', &printf_d},

	{"", 'd', &printf_d}, {"", 'i', &printf_d}, {"h", 'D', &printf_d},
	{"hh", 'D', &printf_d},

	{"h", 'o', &printf_o}, {"hh", 'O', &printf_o},
	{"h", 'u', &printf_u}, {"hh", 'U', &printf_u},

	{"hh", 'b', &printf_b},
	{"h", 'x', &printf_x},
	{"h", 'X', &printf_x}, {"h", 'b', &printf_b},
	{"", 'o', &printf_o}, {"", 'u', &printf_u}, {"", 'x', &printf_x},
	{"", 'X', &printf_x}, {"", 'b', &printf_b}, {"", 'k', &printf_k},
	{"h", 'O', &printf_o},

	{"", 's', &printf_s},

	{"l", 'c', &printf_lc}, {"", 'C', &printf_lc}, {"hh", 'C', &printf_lc},

	{"l", 's', &printf_ls}, {"", 'S', &printf_ls}, {"", 'r', &printf_r},
	{"hh", 'S', &printf_ls},

	{"l", 'd', &printf_d}, {"l", 'i', &printf_d}, {"", 'D', &printf_d},
	{"h", 'U', &printf_d},

	{"l", 'o', &printf_o}, {"l", 'u', &printf_u}, {"l", 'x', &printf_x},
	{"l", 'X', &printf_x}, {"l", 'b', &printf_b}, {"", 'O', &printf_o},
	{"", 'U', &printf_u},

	{"ll", 'd', &printf_d}, {"j", 'd', &printf_d}, {"z", 'd', &printf_d},
	{"l", 'D', &printf_d}, {"ll", 'i', &printf_d}, {"j", 'i', &printf_d},
	{"z", 'i', &printf_d}, {"ll", 'D', &printf_d}, {"j", 'D', &printf_d},
	{"z", 'D', &printf_d},

	{"ll", 'o', &printf_o}, {"j", 'o', &printf_o}, {"z", 'o', &printf_o},
	{"l", 'O', &printf_o}, {"ll", 'O', &printf_o}, {"j", 'O', &printf_o},
	{"z", 'O', &printf_o},
	{"ll", 'u', &printf_u}, {"j", 'u', &printf_u}, {"z", 'u', &printf_u},
	{"l", 'U', &printf_u}, {"ll", 'U', &printf_u}, {"j", 'U', &printf_u},
	{"z", 'U', &printf_u},
	{"ll", 'x', &printf_x}, {"j", 'x', &printf_x}, {"z", 'x', &printf_x},
	{"ll", 'X', &printf_x}, {"j", 'X', &printf_x}, {"z", 'X', &printf_x},
	{"ll", 'b', &printf_b}, {"j", 'b', &printf_b}, {"z", 'b', &printf_b},

	{"l", 'e', &printf_e}, {"", 'e', &printf_e},
	{"l", 'f', &printf_f}, {"", 'f', &printf_f},
	{"l", 'g', &printf_g}, {"", 'g', &printf_g},
	{"l", 'a', &printf_a}, {"", 'a', &printf_a},

	{"L", 'a', &printf_a}, {"", 'A', &printf_a},
	{"L", 'e', &printf_e}, {"", 'E', &printf_e},
	{"L", 'f', &printf_f}, {"", 'F', &printf_f},
	{"L", 'g', &printf_g}, {"", 'G', &printf_g},

	{"", 'p', &printf_p}, {"l", 'p', &printf_p},

	{"l", 'n', &printf_n}, {"ll", 'n', &printf_n}, {"h", 'n', &printf_n},
	{"hh", 'n', &printf_n}, {"j", 'n', &printf_n}, {"z", 'n', &printf_n},
	{"", 'n', &printf_n},

	{"", '\0', NULL},
};

t_va_arg		g_va_arg[] =
{
	{&char_va_arg_int, 3}, {&uchar_va_arg_int, 7}, {&shint_va_arg_int, 9},
	{&intm_va_arg_int, 13},
	{&ushint_va_arg_int, 17}, {&uintm_va_arg_uint, 28}, {&va_arg_str, 29},
	{&wint_va_arg_int, 32}, {&va_arg_chr, 36},
	{&intm_va_arg_lint, 40}, {uintm_va_arg_ulint, 47}, {&va_arg_intm, 57},
	{&va_arg_uintm, 80}, {&ldouble_va_arg_double, 88}, {&va_arg_ldouble, 96},
	{&va_arg_void, 98}
};

#endif
