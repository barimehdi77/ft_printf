/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_whith_zero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 05:45:33 by mbari             #+#    #+#             */
/*   Updated: 2019/12/28 13:25:18 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/libftprintf.h"

void	ft_left(va_list arg, char *s, t_print *val)
{
	int		espace;
	int		size;
	t_args	valofarg;

	valofarg = ft_arg(arg, val);
	while (*s == '-')
		s++;
	espace = ft_atoi(s);
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
	int		espace;
	int		size;
	t_args	valofarg;

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
		return (ft_with_string(espace, type, &valofarg, val));
	else
	{
		size = ft_value_len(&valofarg, val);
		ft_addespace(espace - size, type, val);
	}
	ft_print_arg(&valofarg, val);
	if (espace < 0)
		ft_addespace((-espace) - size, ' ', val);
}

void	ft_with_string(int espace, char type, t_args *value, t_print *val)
{
	char	*str;

	str = value->string;
	ft_addespace(espace, type, val);
	if (espace < 0)
		ft_addespace(-espace, ' ', val);
	if (str == NULL || str[0] == '\0')
		return ;
}

void	ft_negative_number(int value, int espace, t_print *val, char type)
{
	int		size;

	size = ft_strlen(ft_itoa(value));
	if (val->type == 'd' || val->type == 'i')
	{
		if (espace == 0 && value == 0)
			return ;
		if (value < 0 && type == '0')
		{
			ft_putchar('-', val);
			value *= -1;
			(val->point == POINT_NUMBER) ? (size--) : (size);
		}
		if (val->point == NUMBER_POINT && value == 0)
			size = 0;
		ft_addespace(espace - size, type, val);
		(size == 0) ? size : ft_putnbr(value, val);
	}
	else if (val->type == 'u')
	{
		(value < 0) ? (size = 10) : (size);
		ft_addespace(espace - size, type, val);
		ft_putunsignednbr(value, val);
	}
	(espace < 0) ? (ft_addespace((-espace) - size, ' ', val)) : NULL;
}

void	ft_with_point(va_list arg, char *s, t_print *val, char type)
{
	int		espace;
	int		size;
	t_args	valofarg;

	valofarg = ft_arg(arg, val);
	if (*s == '-')
		s++;
	espace = ft_atoi(s + 1);
	size = ft_value_len(&valofarg, val);
	if (val->type != '%')
	{
		if (val->type == 'd' || val->type == 'i' || val->type == 'u')
			return (ft_negative_number(valofarg.number, espace, val, type));
		else if (val->type == 'p')
		{
			ft_addespace(espace - size - 2, type, val);
			ft_putstr("0x", val);
		}
		else if (val->type == 's')
			return (ft_print_string(espace, valofarg.string, val));
		else
			ft_addespace(espace - size, type, val);
	}
	ft_print_arg(&valofarg, val);
}
