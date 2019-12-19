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
}              t_print;

#define NORMAL_FORMS (*(s + i) == 'c' || *(s + i) == 's' || *(s + i) == 'p'\
					|| *(s + i) == 'd' || *(s + i) == 'i' || *(s + i) == 'u'\
					|| *(s + i) == 'x' || *(s + i) == 'X' || *(s + i) == '%')

#define FLAGS_FORMS (ft_isdigit(*(s + i)) || *(s + i) == '0' || *(s + i) == '*'\
					|| *(s + i) == '-' || *(s + i) == '.')

int     ft_printf(const char *s, ...);
void    ft_normal_forms(va_list arg, char *s, t_print *val);
void	ft_flags(va_list arg, const char *s, t_print *val);
void	ft_addespace(int size, char c, t_print *val);
void    ft_call_arg(va_list arg, char *s);
char    ft_check_arg(const char *s);
void	ft_call_s(va_list arg, char *s, t_print *val);
void	ft_call_c(va_list arg, char *s, t_print *val);
void	ft_call_number(va_list arg, char *s, t_print *val);
void	ft_call_x(va_list arg, char *s, t_print *val);
void	ft_call_p(va_list arg, char *s, t_print *val);
void	ft_call_X(va_list arg, char *s, t_print *val);
void	ft_call_percent(char *s, t_print *val);
void	ft_check_espace(va_list arg, char *s, t_print *val);
void	ft_check_zero(va_list arg, char *s, t_print *val);
void	ft_check_left(va_list arg, char *s, t_print *val);
void	ft_check_star(va_list arg, char *s, t_print *val);
void	ft_check_point(va_list arg, char *s, t_print *val);
int     ft_skip(char *s);
char	*ft_decimaltoupperx(unsigned int dic);
char	*ft_decimaltolowerx(unsigned int dic);
void	ft_print_hex(const char *s, unsigned long dic, t_print *val);
char	*ft_addriss(unsigned long dic);
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
void	ft_double_star(va_list arg, char *s, t_print *val);
void    ft_double_star_d_i(va_list arg, t_print *val);
void    ft_double_star_s(va_list arg, t_print *val);
void    ft_double_star_lowerx(va_list arg, t_print *val);
void    ft_double_star_upperx(va_list arg, t_print *val);
void    ft_double_star_u(va_list arg, t_print *val);
void    ft_double_star_c(va_list arg, t_print *val);
void    ft_double_star_percent(va_list arg, t_print *val);
void    ft_double_star_p(va_list arg, char *s, t_print *val);
char 	*ft_pointer(void *p, t_print *val);
char 	*ft_pointer_flags(void *p, t_print *val);

#endif
