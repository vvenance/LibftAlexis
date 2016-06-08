/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaverty <aaverty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 15:07:09 by aaverty           #+#    #+#             */
/*   Updated: 2016/02/08 19:12:34 by aaverty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <wchar.h>
# include "libft.h"
# define COULEUR(param) ft_printf("\033[%sm",param)

typedef struct	s_tabft
{
	char		size_mod_r[3];
	char		convert_r;
	char		*(*ptr)();
}				t_tabft;

typedef struct	s_args
{
	int			arg_select;
	char		option[7];
	int			size_mini;
	int			precision;
	char		size_mod[3];
	char		convert_type;
	char		*(*funcptr)();
}				t_args;

typedef struct	s_va_arg
{
	char		*(*ft_arg)();
	int			i_r;
}				t_va_arg;

int				check_arg(char **format, t_args *args, va_list ap);
int				find_percent(char **str);
int				ft_putstr_args(char *s, t_args args);
int				color(char **str);
int				check_color(char **str);
int				check_background_color(char **str);
void			*lstdel(t_list **alst);
char			*printf_a(long double d, t_args args);
char			*printf_s(char *s, t_args args);
char			*printf_ls(wchar_t *str, t_args args);
char			*printf_lc(wint_t chr, t_args args);
char			*printf_char(char c, t_args args);
char			*printf_d(intmax_t n, t_args args);
char			*printf_hd(short int n, t_args args);
char			*printf_hhd(char n, t_args args);
char			*printf_o(uintmax_t nb, t_args args);
char			*printf_ho(unsigned short int nb, t_args args);
char			*printf_hho(unsigned char nb, t_args args);
char			*printf_u(uintmax_t n, t_args args);
char			*printf_hu(unsigned short int n, t_args args);
char			*printf_hhu(unsigned char n, t_args args);
char			*printf_x(uintmax_t nb, t_args args);
char			*printf_hhx(unsigned char nb, t_args args);
char			*printf_f(long double n, t_args args);
char			*printf_g(long double n, t_args args);
char			*printf_e(long double n, t_args args);
char			*printf_p(void *addr, t_args args);
char			*printf_n(int nb, int *n, t_args args);
char			*printf_b(uintmax_t nb, t_args args);
char			*printf_r(wchar_t *str, t_args args);
char			*printf_k(uintmax_t date, t_args args);
char			*printf_percent(char c, t_args args);
char			*intm_va_arg_int(t_args args, va_list ap);
char			*uintm_va_arg_uint(t_args args, va_list ap);
char			*va_arg_str(t_args args, va_list ap);
char			*char_va_arg_int(t_args args, va_list ap);
char			*wint_va_arg_int(t_args args, va_list ap);
char			*va_arg_chr(t_args args, va_list ap);
char			*intm_va_arg_lint(t_args args, va_list ap);
char			*uintm_va_arg_ulint(t_args args, va_list ap);
char			*va_arg_intm(t_args args, va_list ap);
char			*va_arg_uintm(t_args args, va_list ap);
char			*ldouble_va_arg_double(t_args args, va_list ap);
char			*va_arg_ldouble(t_args args, va_list ap);
char			*va_arg_void(t_args args, va_list ap);
char			*uchar_va_arg_int(t_args args, va_list ap);
char			*shint_va_arg_int(t_args args, va_list ap);
char			*ushint_va_arg_int(t_args args, va_list ap);
char			*va_arg_dtabchar(t_args args, va_list ap);

#endif
