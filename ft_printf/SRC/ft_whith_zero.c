/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_whith_zero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 05:45:33 by mbari             #+#    #+#             */
/*   Updated: 2019/12/23 05:45:34 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/libftprintf.h"

void ft_initialized(t_args *arg)
{
	arg->number = 0;
	arg->string = NULL;
	arg->int_str = 0;
}

t_args ft_arg(va_list arg, t_print *val)
{
	t_args ret;

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
		ret.string = ft_decimaltohex((unsigned long)va_arg(arg, void *), val->type);
	else if (val->type == '%')
		ret.number = '%';
	if (val->type == 's' || val->type == 'x' || 
		val->type == 'X' || val->type == 'p')
		ret.int_str = STRING;
	else if (val->type == 'd' || val->type == 'i' || val->type == 'u')
		ret.int_str = NUMBER;
	else
		ret.int_str = CHAR;
	return (ret);
}

void	ft_left(va_list arg, char *s, t_print *val)
{
	int espace;
	int size;
	t_args valofarg;

	valofarg = ft_arg(arg, val);
	espace = ft_atoi(s + 1);
	size = ft_value_len(&valofarg, val);
	if (val->type == 'p')
	{
		ft_putstr("0x", val);
		ft_print_arg(&valofarg, val);
		ft_addespace(espace - size - 2, ' ', val);
	}
	else
	{
		ft_print_arg(&valofarg, val);
		ft_addespace(espace - size, ' ', val);
	}
}

void	ft_with_zeros(va_list arg, char *s, t_print *val, char type)
{
	int espace;
	int size;
	t_args valofarg;

	valofarg = ft_arg(arg, val);
	espace = ft_atoi(s);
	size = 1;
	if (val->type == 'd' || val->type == 'i' || val->type == 'u')
		return (ft_negative_number(valofarg.number, espace, val, type));
	else if (val->type == 'p')
	{
		size = ft_strlen(valofarg.string);
		ft_addespace(espace - size - 2, type, val);
		ft_putstr("0x", val);
	}
	else if (val->type == 's' && val->point == NUMBER_POINT)
		ft_addespace(espace - size, type, val);
	else
	{
		size = ft_value_len(&valofarg, val);
		ft_addespace(espace - size, type, val);
	}
	ft_print_arg(&valofarg, val);
}

void	ft_negative_number(int value, int espace, t_print *val, char type)
{
	int size;

	if (val->type == 'd' || val->type == 'i')
	{
		size = ft_strlen(ft_itoa(value));
		if (value < 0 && type == '0')
		{
			ft_putchar('-', val);
			value *= -1;
		}
		if (val->point == NUMBER_POINT && value == 0)
			size = 0;
		ft_addespace(espace - size, type, val);
		(size == 0) ? size : ft_putnbr(value, val);
	}
	else if (val->type == 'u')
	{
		if (value < 0)
			size = 10;
		else
			size = ft_strlen(ft_itoa(value));
		ft_addespace(espace - size, type, val);
		ft_putunsignednbr(value, val);
	}
}