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

#include <stdarg.h>
#include <string.h>
#include <stdio.h>


int     ft_printf(const char *s, ...);
void    ft_addespace(int size, char c);
void    ft_call_arg(va_list arg, char *s);
char    ft_check_arg(const char *s);
void    ft_call_s(va_list arg, char *s);
void    ft_call_c(va_list arg, char *s);
void    ft_call_x(va_list arg, char *s);
void    ft_call_X(va_list arg, char *s);
void    ft_call_p(va_list arg, char *s);
void    ft_call_number(va_list arg, char *s);
void    ft_call_percent(char *s);
void    ft_check_espace(va_list arg, char *s);
void    ft_check_zero(va_list arg, char *s);
void    ft_check_left(va_list arg, char *s);
void    ft_check_point(va_list arg, char *s);
int     ft_skip(char *s);
char    *ft_decimaltoHEX(int dic);
char    *ft_decimaltohex(int dic);
void    ft_print_hex(const char *s, int dic);
char    *ft_addriss(int dic);
void    ft_call_point_s(va_list arg, char *s);
void    ft_call_zero_s(va_list arg, char *s);
int     ft_numberofzeros(char *valofarg, char *s);
void    ft_call_zero_c(va_list arg, char *s);
void    ft_call_zero_number(va_list arg, char *s);
void    ft_call_zero_x(va_list arg, char *s);
void    ft_call_zero_X(va_list arg, char *s);
void    ft_call_left_p(va_list arg, char *s);
void    ft_call_zero_percent(char *s);
void    ft_call_left_s(va_list arg, char *s);
void    ft_call_left_c(va_list arg, char *s);
void    ft_call_left_number(va_list arg, char *s);
void    ft_call_left_x(va_list arg, char *s);
void    ft_call_left_X(va_list arg, char *s);
void    ft_call_left_percent(char *s);
void    ft_check_star(va_list arg, char *s);
void    ft_call_star_s(va_list arg, char *s);
void    ft_call_star_c(va_list arg, char *s);
void    ft_call_star_number(va_list arg, char *s);
void    ft_call_star_x(va_list arg, char *s);
void    ft_call_star_X(va_list arg, char *s);
void    ft_call_star_p(va_list arg, char *s);
void    ft_call_star_percent(va_list arg, char *s);