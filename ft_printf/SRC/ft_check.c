/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 00:17:07 by mbari             #+#    #+#             */
/*   Updated: 2019/12/02 00:17:12 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/libftprintf.h"

void	ft_check_espace(va_list arg, char *s, t_print *val)
{
	if (ft_check_arg(s) == 's')
		ft_call_s(arg, s, val);
	else if (ft_check_arg(s) == 'c')
		ft_call_c(arg, s, val);
	else if (ft_check_arg(s) == 'd' || ft_check_arg(s) == 'i')
		ft_call_number(arg, s, val);
	else if (ft_check_arg(s) == 'u')
		ft_call_number(arg, s, val);
	else if (ft_check_arg(s) == 'p')
		ft_call_p(arg, s, val);
	else if (ft_check_arg(s) == 'x')
		ft_call_x(arg, s, val);
	else if (ft_check_arg(s) == 'X')
		ft_call_X(arg, s, val);
	else if (ft_check_arg(s) == '%')
		ft_call_percent(s, val);
	else if (ft_check_arg(s) == '.')
		ft_call_point_s(arg, s, val);
}

void	ft_check_zero(va_list arg, char *s, t_print *val)
{
	if (ft_check_arg(s) == 's')
		ft_call_zero_s(arg, s, val);
	else if (ft_check_arg(s) == 'c')
		ft_call_zero_c(arg, s, val);
	else if (ft_check_arg(s) == '.')
		ft_call_point_s(arg, s, val);
	else if (ft_check_arg(s) == 'd' || ft_check_arg(s) == 'i')
		ft_call_zero_d_i(arg, s, val);
	else if (ft_check_arg(s) == 'u')
		ft_call_zero_u(arg, s, val);
	else if (ft_check_arg(s) == 'p')
		ft_call_zero_p(arg, s, val);
	else if (ft_check_arg(s) == 'x')
		ft_call_zero_x(arg, s, val);
	else if (ft_check_arg(s) == 'X')
		ft_call_zero_X(arg, s, val);
	else if (ft_check_arg(s) == '%')
		ft_call_zero_percent(s, val);
}

void	ft_check_left(va_list arg, char *s, t_print *val)
{
	if (ft_check_arg(s) == 's')
		ft_call_left_s(arg, s, val);
	else if (ft_check_arg(s) == 'c')
		ft_call_left_c(arg, s, val);
	else if (ft_check_arg(s) == 'd' || ft_check_arg(s) == 'i')
		ft_call_left_number(arg, s, val);
	else if (ft_check_arg(s) == 'u')
		ft_call_left_number(arg, s, val);
	else if (ft_check_arg(s) == 'p')
		ft_call_left_p(arg, s, val);
	else if (ft_check_arg(s) == 'x')
		ft_call_left_x(arg, s, val);
	else if (ft_check_arg(s) == 'X')
		ft_call_left_X(arg, s, val);
	else if (ft_check_arg(s) == '%')
		ft_call_left_percent(s, val);
}

void	ft_check_star(va_list arg, char *s, t_print *val)
{
	if (ft_check_arg(s) == 's')
		ft_call_star_s(arg, val);
	else if (ft_check_arg(s) == 'c')
		ft_call_star_c(arg, val);
	else if (ft_check_arg(s) == 'd' || ft_check_arg(s) == 'i')
		ft_call_star_number(arg, val);
	else if (ft_check_arg(s) == 'u')
		ft_call_star_number(arg, val);
	else if (ft_check_arg(s) == 'p')
		ft_call_star_p(arg, val);
	else if (ft_check_arg(s) == 'x')
		ft_call_star_x(arg, val);
	else if (ft_check_arg(s) == 'X')
		ft_call_star_X(arg, val);
	else if (ft_check_arg(s) == '%')
		ft_call_star_percent(arg, val);
}

void	ft_check_point(va_list arg, char *s, t_print *val)
{
	if (ft_check_arg(s) == 's')
		ft_call_zero_or_point_s(arg, s, val);
	else if (ft_check_arg(s) == 'c')
		ft_putchar(va_arg(arg, int), val);
	else if (ft_check_arg(s) == 'd' || ft_check_arg(s) == 'i')
		ft_call_zero_d_i(arg, s, val);
	else if (ft_check_arg(s) == 'u')
		ft_call_zero_u(arg, s, val);
	else if (ft_check_arg(s) == 'p')
		ft_print_hex(s, va_arg(arg, int), val);
	else if (ft_check_arg(s) == 'x')
		ft_call_zero_x(arg, s, val);
	else if (ft_check_arg(s) == 'X')
		ft_call_zero_X(arg, s, val);
	else if (ft_check_arg(s) == '%')
		ft_call_zero_percent(s, val);
}
