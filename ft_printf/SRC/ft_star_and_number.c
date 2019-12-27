/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_star_and_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 15:37:13 by mbari             #+#    #+#             */
/*   Updated: 2019/12/20 15:37:14 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/libftprintf.h"

void	ft_star_number(va_list arg, char *s, t_print *val)
{
	int		espace;
	int		zeros;
	int		size;
	t_args	value;

	espace = va_arg(arg, int);
	zeros = ft_atoi(s + 2);
	value = ft_arg(arg, val);
	size = 1;
	if (value.int_str == NUMBER)
		size = ft_strlen(ft_itoa(value.number));
	else if (value.int_str == STRING)
		size = ft_strlen(value.string);
	if (value.number < 0)
		return (ft_neg_number(value.number, espace, zeros, val));
	if (val->type == 's')
		return (ft_star_string(espace, zeros, value.string, val));
	ft_addespace((espace - zeros), ' ', val);
	if (value.number == 0 && zeros == 0)
		return ;
	ft_addespace((zeros - size), '0', val);
	ft_print_arg(&value, val);
	if (espace < 0)
		ft_addespace(((-espace) - zeros), ' ', val);
}

void	ft_neg_number(int value, int espace, int zeros, t_print *val)
{
	int		size;

	size = ft_strlen(ft_itoa(value));
	if (val->type == 'd' || val->type == 'i')
	{
		ft_addespace((espace - zeros) - 1, ' ', val);
		size--;
		ft_putchar('-', val);
		value *= -1;
		ft_addespace((zeros - size), '0', val);
		ft_putnbr(value, val);
	}
	else if (val->type == 'u')
	{
		if (value < 0)
			size = 10;
		else
			size = ft_strlen(ft_itoa(value));
		ft_addespace((espace - zeros) - 1, ' ', val);
		ft_addespace((zeros - size), '0', val);
		ft_putunsignednbr(value, val);
	}
}
