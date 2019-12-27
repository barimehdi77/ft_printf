/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 03:27:17 by mbari             #+#    #+#             */
/*   Updated: 2019/12/11 03:27:19 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/libftprintf.h"

void	ft_print_string(int size, char *str, t_print *val)
{
	int		i;

	i = 0;
	if (size < 0)
		size = ft_strlen(str);
	if (str == NULL)
		str = "(null)";
	while (size > i && str[i] != '\0')
	{
		ft_putchar(str[i], val);
		i++;
	}
}

void	ft_star_string(int espace, int size, char *str, t_print *val)
{
	int		strlen;

	strlen = ft_strlen(str);
	(size > strlen) ? (size = strlen) : strlen;
	ft_addespace((espace - size), ' ', val);
	ft_print_string(size, str, val);
	if (espace < 0)
		ft_addespace(((-espace) - size), ' ', val);
}

void	ft_just_star(va_list arg, t_print *val)
{
	int		espace;
	int		size;
	t_args	value;

	espace = va_arg(arg, int);
	value = ft_arg(arg, val);
	size = ft_value_len(&value, val);
	ft_addespace(espace - size, ' ', val);
	ft_print_arg(&value, val);
	if (espace < 0)
		ft_addespace((-espace) - size, ' ', val);
}
