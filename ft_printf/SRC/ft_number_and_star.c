/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_and_star.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 16:07:21 by mbari             #+#    #+#             */
/*   Updated: 2019/12/28 13:24:45 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/libftprintf.h"

void	ft_number_star(va_list arg, char *s, t_print *val)
{
	int		espace;
	int		zeros;
	int		size;
	t_args	value;

	zeros = va_arg(arg, int);
	espace = ft_atoi(s);
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
}
