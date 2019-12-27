/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 23:48:39 by mbari             #+#    #+#             */
/*   Updated: 2019/12/27 23:48:41 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		ft_skip(char *s)
{
	int		i;

	i = 0;
	while (s[i] != 'c' && s[i] != 's' && s[i] != 'p' &&
			s[i] != 'd' && s[i] != 'i' && s[i] != 'u' &&
				s[i] != 'x' && s[i] != 'X' && s[i] != '%')
		i++;
	return (i);
}

void	ft_set_val(t_print *val)
{
	val->star = 0;
	val->point = 0;
	val->whith = 0;
	val->left = 0;
	val->zeros = 0;
}

void	ft_flags(va_list arg, const char *s, t_print *val)
{
	ft_flags_count(s, val);
	ft_select_flag(arg, s, val);
}

void	ft_initialized(t_args *arg)
{
	arg->number = 0;
	arg->string = NULL;
	arg->int_str = 0;
}

t_args	ft_arg(va_list arg, t_print *val)
{
	t_args	ret;

	ft_initialized(&ret);
	if (val->type == 'c')
		ret.number = va_arg(arg, int);
	else if (val->type == 's')
		ret.string = va_arg(arg, char *);
	else if (val->type == 'd' || val->type == 'i')
		ret.number = va_arg(arg, int);
	else if (val->type == 'u')
		ret.number = va_arg(arg, int);
	else if (val->type == 'x' || val->type == 'X')
		ret.string = ft_decimaltohex(va_arg(arg, int), val->type);
	else if (val->type == 'p')
		ret.string = ft_decimaltohex((unsigned long)va_arg(arg, void *),
			val->type);
	else if (val->type == '%')
		ret.number = '%';
	if (val->type == 's' || val->type == 'x' ||
			val->type == 'X' || val->type == 'p')
		ret.int_str = STRING;
	else if (val->type == 'd' || val->type == 'i' || val->type == 'u')
		ret.int_str = NUMBER;
	else
		ret.int_str = CHAR;
	if (ret.int_str == STRING)
		ret.number = 1;
	return (ret);
}
