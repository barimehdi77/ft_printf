/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 01:17:40 by mbari             #+#    #+#             */
/*   Updated: 2019/12/01 01:17:42 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <stdarg.h>
#include <string.h>
#include <stdio.h>

typedef struct s_print
{
	int     count;
	int		star;
	int		point;
	int		whith;
	int		zeros;
	int		left;
	char	type;
}              t_print;

typedef	struct s_arg
{
	char *string;
	int number;
	int int_str;
}				t_args;

#define CSPER_FORMS *(s + i) == 'c' || *(s + i) == 's' || *(s + i) == '%'
#define DIU_FORMS *(s + i) == 'd' || *(s + i) == 'i' || *(s + i) == 'u'
#define HEXP_FORMS *(s + i) == 'x' || *(s + i) == 'X' || *(s + i) == 'p'

#define CSPER *(s + i) != 'c' && *(s + i) != 's' && *(s + i) != '%'
#define DIU *(s + i) != 'd' && *(s + i) != 'i' && *(s + i) != 'u'
#define HEXP *(s + i) != 'x' && *(s + i) != 'X' && *(s + i) != 'p'

#define WITH_FLAG ft_isdigit(*(s + i), &val) || *(s + i) == '0' || *(s + i) == '*'
#define WHITH_FLAGS *(s + i) == '-' || *(s + i) == '.'
#define ON 1
#define OFF 0
#define STAR_NUMBER 2
#define NUMBER_STAR 3
#define JUST_NUMBERS 4
#define STAR_POINT 5
#define NUMBER_POINT 6
#define POINT_STAR 7
#define POINT_NUMBER 8

#define STRING 1
#define NUMBER 0
#define CHAR 2

int     ft_printf(const char *s, ...);
void    ft_normal_forms(va_list arg, const char *s, t_print *val);
void	ft_flags(va_list arg, const char *s, t_print *val);
void	ft_select_flag(va_list arg, const char *s, t_print *val);
void	ft_flags_count(const char *s, t_print *val);
char	ft_type(const char *s);
void	ft_addespace(int size, char c, t_print *val);
void    ft_call_arg(va_list arg, char *s);
char    ft_check_arg(const char *s);
void	ft_call_s(va_list arg, char *s, t_print *val);
void    ft_call_c_d_i(va_list arg, char *s, t_print *val, char type);
void    ft_call_u_percent(va_list arg, char *s, t_print *val, char type);
void    ft_call_hex(va_list arg, char *s, t_print *val, char type);
void    ft_call_p(va_list arg, char *s, t_print *val, char type);
void	ft_check_espace(va_list arg, char *s, t_print *val);
void	ft_check_zero(va_list arg, char *s, t_print *val);
void	ft_check_left(va_list arg, char *s, t_print *val);
void	ft_check_star(va_list arg, char *s, t_print *val);
void	ft_check_point(va_list arg, char *s, t_print *val);
int     ft_skip(char *s);
char	*ft_decimaltohex(unsigned long dic, char type);
void	ft_call_point_s(va_list arg, char *s, t_print *val);
void	ft_call_zero_or_point_s(va_list arg, char *s, t_print *val);
void	ft_call_zero_s(va_list arg, char *s, t_print *val);
int     ft_numberofzeros(char *valofarg, char *s);
void	ft_call_zero_c(va_list arg, char *s, t_print *val);
void	ft_call_zero_d_i(va_list arg, char *s, t_print *val);
void	ft_call_zero_u(va_list arg, char *s, t_print *val);
void	ft_call_zero_x(va_list arg, char *s, t_print *val);
void	ft_call_zero_X(va_list arg, char *s, t_print *val);
void	ft_call_zero_p(va_list arg, char *s, t_print *val);
void	ft_call_zero_percent(char *s, t_print *val);
int		ft_two_flags(char *s);
void	ft_call_left_s(va_list arg, char *s, t_print *val);
void	ft_call_left_c(va_list arg, char *s, t_print *val);
void	ft_call_left_number(va_list arg, char *s, t_print *val);
void	ft_call_left_x(va_list arg, char *s, t_print *val);
void	ft_call_left_X(va_list arg, char *s, t_print *val);
void	ft_call_left_p(va_list arg, char *s, t_print *val);
void	ft_call_left_percent(char *s, t_print *val);
void	ft_call_star_s(va_list arg, t_print *val);
void	ft_call_star_c(va_list arg, t_print *val);
void	ft_call_star_number(va_list arg, t_print *val);
void	ft_call_star_x(va_list arg, t_print *val);
void	ft_call_star_p(va_list arg, t_print *val);
void	ft_call_star_X(va_list arg, t_print *val);
void	ft_call_star_percent(va_list arg, t_print *val);
void	ft_star_or_number(va_list arg, char *s, t_print *val);
void	ft_star_and_number(va_list arg, char *s, t_print *val);
void	ft_number_and_star(va_list arg, char *s, t_print *val);
void	ft_double_star(va_list arg, char *s, t_print *val);
void    ft_double_star_d_i(va_list arg, t_print *val);
void    ft_double_star_s(va_list arg, t_print *val);
void    ft_double_star_lowerx(va_list arg, t_print *val);
void    ft_double_star_upperx(va_list arg, t_print *val);
void    ft_double_star_u(va_list arg, t_print *val);
void    ft_double_star_c(va_list arg, t_print *val);
void    ft_double_star_percent(va_list arg, t_print *val);
void    ft_double_star_p(va_list arg, t_print *val);
char 	*ft_pointer(void *p, t_print *val);
void    ft_one_star_s(va_list arg, char *s, t_print *val);
void    ft_one_star_d_i(va_list arg, char *s, t_print *val);
void    ft_one_number_hex(va_list arg, char *s, t_print *val);
void    ft_one_star_u(va_list arg, char *s, t_print *val);
void    ft_one_star_c(va_list arg, t_print *val);
void    ft_one_star_percent(va_list arg, t_print *val);
void    ft_one_star_p(va_list arg, char *s, t_print *val);
void    ft_one_number_s(va_list arg, char *s, t_print *val);
void    ft_one_number_d_i(va_list arg, char *s, t_print *val);
void    ft_one_star_hex(va_list arg, char *s, t_print *val);
void    ft_one_number_u(va_list arg, char *s, t_print *val);
void    ft_one_number_c(va_list arg, char *s, t_print *val);
void    ft_one_number_percent(va_list arg, char *s, t_print *val);
void    ft_one_number_p(va_list arg, char *s, t_print *val);
void	ft_number_or_star(va_list arg, char *s, t_print *val);
void    ft_double_number_percent(char *s, t_print *val);
void    ft_double_number_c(va_list arg, char *s, t_print *val);
void    ft_double_number_u(va_list arg, char *s, t_print *val);
void    ft_double_number_upperx(va_list arg, char *s, t_print *val);
void    ft_double_number_lowerx(va_list arg, char *s, t_print *val);
void    ft_double_number_d_i(va_list arg, char *s, t_print *val);
void	ft_double_number(va_list arg, char *s, t_print *val, int skip);
void	ft_espace(va_list arg, char *s, t_print *val, int skip);
void	ft_which_point(char *s, t_print *val);
void	ft_print_point(va_list arg, char *s, t_print *val);
void	ft_print_hex(const char *s, unsigned int dic, t_print *val);
void	ft_just_point(va_list arg, char *s, t_print *val);
void	ft_print(va_list arg, char *s, t_print *val);
void	ft_left(va_list arg, char *s, t_print *val);
void	ft_with_zeros(va_list arg, char *s, t_print *val, char type);
void	ft_negative_number(int value, int espace, t_print *val, char type);
t_args 	ft_arg(va_list arg, t_print *val);
void	ft_initialized(t_args *arg);
void	ft_print_arg(t_args *valofarg, t_print *val);
int		ft_value_len(t_args *arg, t_print *val);
void    ft_double_numbers(va_list arg, char *s, t_print *val);
int ft_skip_number(char *s);
void	ft_print_string(int size, char *str, t_print *val);
void    ft_double_number_p(int espace, int zeros, t_print *val);
void ft_double_number_neg(int espace, int zeros, t_args *value, t_print *val);
void    ft_double_number_s(int espace, int zeros, t_args *str, t_print *val);

#endif
