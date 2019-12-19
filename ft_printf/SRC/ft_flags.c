/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 21:54:06 by mbari             #+#    #+#             */
/*   Updated: 2019/12/15 21:54:08 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../libft/libft.h"
#include "../includes/libftprintf.h"

void	ft_flags(va_list arg, const char *s, t_print *val)
{
	if (ft_isdigit(*s))
		ft_check_espace(arg, (char *)s, val);
	else if (*s == '0')
		ft_check_zero(arg, (char *)s, val);
	else if (*s == '*' && *(s + 1) != '.')
		ft_check_star(arg, (char *)s, val);
	else if (*s == '-')
		ft_check_left(arg, (char *)s, val);
	else if (*s == '.' )
		ft_check_point(arg, (char *)(s + 1), val);
	else if (*s == '*' && *(s + 1) == '.')
		ft_star_or_number(arg, (char *)(s + 2), val);
}

void	ft_star_or_number(va_list arg, char *s, t_print *val)
{
	if (ft_isdigit(*s))
		ft_star_and_number(arg, s, val);
	else if (*s == '*')
		ft_double_star(arg, s, val);
}

void	ft_star_and_number(va_list arg, char *s, t_print *val)
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

void	ft_double_star(va_list arg, char *s, t_print *val)
{
	if (ft_check_arg(s) == 's')
		ft_double_star_s(arg, val);
	else if (ft_check_arg(s) == 'c')
		ft_double_star_c(arg, val);
	else if (ft_check_arg(s) == 'd' || ft_check_arg(s) == 'i')
		ft_double_star_d_i(arg, val);
	else if (ft_check_arg(s) == 'u')
		ft_double_star_u(arg, val);
	else if (ft_check_arg(s) == 'p')
		ft_double_star_p(arg, s,val);
	else if (ft_check_arg(s) == 'x')
		ft_double_star_lowerx(arg, val);
	else if (ft_check_arg(s) == 'X')
		ft_double_star_upperx(arg, val);
	else if (ft_check_arg(s) == '%')
		ft_double_star_percent(arg, val);
}