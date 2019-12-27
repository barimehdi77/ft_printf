/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 00:16:58 by mbari             #+#    #+#             */
/*   Updated: 2019/12/02 00:17:01 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/libftprintf.h"

void	ft_point_star(va_list arg, t_print *val)
{
	int		zeros;
	int		size;
	t_args	value;

	zeros = va_arg(arg, int);
	value = ft_arg(arg, val);
	size = ft_value_len(&value, val);
	if (value.number < 0)
	{
		ft_putchar('-', val);
		value.number *= -1;
		size--;
	}
	if (value.number == 0 && zeros == 0)
		return ;
	if (val->type == 's')
		return (ft_print_string(zeros, value.string, val));
	ft_addespace(zeros - size, '0', val);
	ft_print_arg(&value, val);
}

void	ft_star_point(va_list arg, t_print *val)
{
	int		espace;
	int		size;
	t_args	value;

	espace = va_arg(arg, int);
	value = ft_arg(arg, val);
	size = ft_value_len(&value, val);
	if (val->type == 's')
	{
		if (espace < 0)
			espace *= -1;
		ft_addespace(espace, ' ', val);
		return ;
	}
	else
		ft_addespace(espace - size, ' ', val);
	ft_print_arg(&value, val);
	if (espace < 0)
		ft_addespace((-espace) - size, ' ', val);
}

void	ft_double_star(va_list arg, t_print *val)
{
	int		zeros;
	int		espace;
	int		print;
	int		size;
	t_args	value;

	espace = va_arg(arg, int);
	zeros = va_arg(arg, int);
	value = ft_arg(arg, val);
	print = zeros;
	size = ft_value_len(&value, val);
	if (val->type != 's')
		(zeros == 0) ? (print = size) : (print = zeros);
	if (val->type == 's')
		return (ft_double_str(value.string, espace, zeros, val));
	ft_addespace(espace - print, ' ', val);
	ft_addespace(zeros - size, '0', val);
	if (value.number == 0 && zeros == 0)
		return ;
	ft_print_arg(&value, val);
	if (espace < 0)
		ft_addespace((-espace) - print, ' ', val);
}

void	ft_double_str(char *str, int espace, int zeros, t_print *val)
{
	int		size;
	int		print;

	size = ft_strlen(str);
	(zeros > size) ? (print = size) : (print = zeros);
	if (str == NULL)
		str = "(null)";
	if (str[0] == '\0')
		ft_addespace(espace, ' ', val);
	else
		ft_addespace(espace - print, ' ', val);
	return (ft_print_string(print, str, val));
}
