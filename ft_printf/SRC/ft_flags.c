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
	ft_flags_count( s, val);
	ft_select_flag(arg, s, val);
}

void	ft_select_flag(va_list arg, const char *s, t_print *val)
{
	if (val->whith == ON && *s != '0' && val->left == OFF && val->point == OFF)
		ft_with_zeros(arg, (char *)s, val, ' ');
	else if (val->zeros == ON && *s == '0')
		ft_with_zeros(arg, (char *)s, val, '0');
	/*else if (val->star == ON && val->point == OFF) 
		ft_check_star(arg, (char *)s, val);*/
	else if (val->left == ON)
		ft_left(arg, (char *)s, val);
	else if (val->point == ON)
	{
		ft_which_point((char *)s, val);
		ft_print_point(arg, (char *)s, val);
	}
	/*else if (val->star == ON && val->point == OFF)
		ft_star_or_number(arg, (char *)(s + 2), val);*/
}

void	ft_which_point(char *s, t_print *val)
{
	while (*s != val->type)
	{
		if (*s == '.')
		{
			if (*(s - 1) == '*' && ft_isdigit(*(s + 1), val))
				val->point = STAR_NUMBER;
			else if (ft_isdigit(*(s - 1), val) && *(s + 1) == '*')
				val->point = NUMBER_STAR;
			else if (ft_isdigit(*(s - 1), val) && ft_isdigit(*(s + 1), val))
				val->point = JUST_NUMBERS;
			else if (*(s - 1) == '*' && *(s + 1) == val->type)
				val->point = STAR_POINT;
			else if (*(s + 1) == '*' && *(s - 1) == '%')
				val->point = POINT_STAR;
			else if (ft_isdigit(*(s - 1), val) && *(s + 1) == val->type)
				val->point = NUMBER_POINT;
			else if (ft_isdigit(*(s + 1), val) && *(s + 1) == '%')
				val->point = POINT_NUMBER;
		}
		s++;
	}
}

void	ft_print_point(va_list arg, char *s, t_print *val)
{
	if (val->point == ON)
		ft_just_point(arg, s, val);
	else if (val->point == STAR_NUMBER)
		ft_star_and_number(arg, s, val);
	else if (val->point == NUMBER_STAR)
		ft_number_and_star(arg, s, val);
	else if (val->point == JUST_NUMBERS)
		ft_double_numbers(arg, s, val);
	else if (val->point == STAR_POINT)
		val->point = POINT_STAR;
	else if (val->point == NUMBER_POINT)
		ft_with_zeros(arg, s, val, ' ');
	else if (val->point == POINT_STAR)
		val->point = POINT_NUMBER;
	else if (val->point == POINT_NUMBER)
		val->point = POINT_NUMBER;
}

void	ft_print(va_list arg, char *s, t_print *val)
{
	char *ptr;
	
	ptr = NULL;
	if (val->type == 'c')
		ft_putchar(va_arg(arg, int), val);
	else if (val->type == 's')
		ft_putstr(va_arg(arg, char *), val);
	else if (val->type == 'd' || val->type == 'i')
		ft_putnbr(va_arg(arg, int), val);
	else if (val->type == 'u')
		ft_putunsignednbr(va_arg(arg, int), val);
	else if (val->type == 'x' || val->type == 'X')
		ft_print_hex(s, va_arg(arg, int), val);
	else if (val->type == 'p')
	{
		ptr = ft_pointer(va_arg(arg, void *), val);
		ft_putstr(ptr, val);
		free(ptr);
	}
	else if (val->type == '%')
		ft_putchar('%', val);
}

void	ft_just_point(va_list arg, char *s, t_print *val)
{
	if (val->type == 's')
		return;
	ft_print(arg, s, val);
}

void	ft_star_and_number(va_list arg, char *s, t_print *val)
{
	if (val->type == 's')
		ft_one_star_s(arg, (s + 2), val);
	else if (val->type == 'c')
		ft_one_star_c(arg, val);
	else if (val->type == 'd' || ft_check_arg(s) == 'i')
		ft_one_star_d_i(arg, (s + 2), val);
	else if (val->type == 'u')
		ft_one_star_u(arg, (s + 2), val);
	else if (val->type == 'p')
		ft_one_star_p(arg, (s + 2), val);
	else if (val->type == 'x')
		ft_one_star_hex(arg, (s + 2), val);
	else if (val->type == 'X')
		ft_one_star_hex(arg, (s + 2), val);
	else if (val->type == '%')
		ft_one_star_percent(arg, val);
}

void	ft_number_and_star(va_list arg, char *s, t_print *val)
{
	if (val->type == 's')
		ft_one_number_s(arg, s, val);
	else if (val->type == 'c')
		ft_one_number_c(arg, s, val);
	else if (val->type == 'd' || ft_check_arg(s) == 'i')
		ft_one_number_d_i(arg, s, val);
	else if (val->type == 'u')
		ft_one_number_u(arg, s, val);
	else if (val->type == 'p')
		ft_one_number_p(arg, s, val);
	else if (val->type == 'x')
		ft_one_number_hex(arg, s, val);
	else if (val->type == 'X')
		ft_one_number_hex(arg, s, val);
	else if (val->type == '%')
		ft_one_number_percent(arg, s, val);
}

//------------------------------------------------------------------------------------------------//
/*void	ft_star_or_number(va_list arg, char *s, t_print *val)
{
	if (ft_isdigit(*s) || *s == '0')
		ft_star_and_number(arg, s, val);
	else if (*s == '*')
		ft_double_star(arg, s, val);
}

void	ft_espace(va_list arg, char *s, t_print *val, int skip)
{
	if (ft_check_arg(s + skip) == 's')
		ft_call_s(arg, s, val, 1);
	else if (ft_check_arg(s + skip) == 'c')
		ft_call_c(arg, s, val);
	else if (ft_check_arg(s + skip) == 'd' || ft_check_arg(s) == 'i')
		ft_call_number(arg, s, val, 1);
	else if (ft_check_arg(s + skip) == 'u')
		ft_call_u(arg, s, val, 1);
	else if (ft_check_arg(s + skip) == 'p')
		ft_call_p(arg, s, val);
	else if (ft_check_arg(s + skip ) == 'x')
		ft_call_x(arg, s, val);
	else if (ft_check_arg(s + skip) == 'X')
		ft_call_X(arg, s, val);
	else if (ft_check_arg(s + skip) == '%')
		ft_call_percent(s, val);
}

void	ft_number_or_star(va_list arg, char *s, t_print *val)
{
	int skip;

	skip = ft_strlen(ft_itoa(ft_atoi(s)));
	s += skip;
	if (ft_isdigit(*(s + 1)) || *(s + 1) == '0')
		ft_double_number(arg, (s - skip), val, skip);
	else if (*(s + 1) == '*')
		ft_number_and_star(arg, (s - skip), val);
	else if (*(s + 1) == ft_check_arg(s))
		ft_espace(arg, (s - skip), val, skip);
}*/

/*void	ft_double_number(va_list arg, char *s, t_print *val, int skip)
{
	if (ft_check_arg(s + skip) == 's')
		ft_double_number_s(arg, s, val);
	else if (ft_check_arg(s + skip) == 'c')
		ft_double_number_c(arg, s, val);
	else if (ft_check_arg(s + skip) == 'd' || ft_check_arg(s) == 'i')
		ft_double_number_d_i(arg, s, val);
	else if (ft_check_arg(s + skip) == 'u')
		ft_double_number_u(arg, s, val);
	else if (ft_check_arg(s + skip) == 'p')
		ft_double_number_p(arg, s, val);
	else if (ft_check_arg(s + skip) == 'x')
		ft_double_number_lowerx(arg, s, val);
	else if (ft_check_arg(s + skip) == 'X')
		ft_double_number_upperx(arg, s, val);
	else if (ft_check_arg(s + skip) == '%')
		ft_double_number_percent(s, val);
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
		ft_double_star_p(arg, val);
	else if (ft_check_arg(s) == 'x')
		ft_double_star_lowerx(arg, val);
	else if (ft_check_arg(s) == 'X')
		ft_double_star_upperx(arg, val);
	else if (ft_check_arg(s) == '%')
		ft_double_star_percent(arg, val);
}

*/