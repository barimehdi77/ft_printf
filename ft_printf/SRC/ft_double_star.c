/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_star.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 01:24:00 by mbari             #+#    #+#             */
/*   Updated: 2019/12/19 01:24:01 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/libftprintf.h"

void    ft_double_star_d_i(va_list arg, t_print *val)
{
	int espace;
	int zeros;
	int size;
	int valofarg;

	espace = va_arg(arg, int);
	zeros = va_arg(arg, int);
	valofarg = va_arg(arg, int);
	if (valofarg < 0)
	{
		valofarg *= -1;
		espace--;
		ft_addespace((espace - zeros), ' ', val);
		ft_putchar('-', val);
	}
	else
		ft_addespace((espace - zeros), ' ', val);
	size = ft_strlen(ft_itoa(valofarg));
	ft_addespace((zeros - size), '0', val);
	ft_putnbr(valofarg, val);
}

void    ft_double_star_s(va_list arg, t_print *val)
{
	int espace;
	int numberofchar;
	int i;
	char *valofarg;

	espace = va_arg(arg, int);
	numberofchar = va_arg(arg, int);
	valofarg = va_arg(arg, char *);
	i = 0;
	ft_addespace((espace - numberofchar), ' ', val);
	while (numberofchar != 0 && valofarg[i] != '\0')
	{
		ft_putchar(valofarg[i], val);
		numberofchar--;
		i++;
	}
}

void    ft_double_star_lowerx(va_list arg, t_print *val)
{
	int espace;
	int zeros;
	int size;
	int valofarg;

	espace = va_arg(arg, int);
	zeros = va_arg(arg, int);
	valofarg = va_arg(arg, int);
	size = ft_strlen(ft_itoa(valofarg));
	ft_addespace((espace - zeros), ' ', val);
	ft_addespace((zeros - size), '0', val);
	ft_putstr(ft_decimaltolowerx(valofarg), val);
}

void    ft_double_star_upperx(va_list arg, t_print *val)
{
	int espace;
	int zeros;
	int size;
	int valofarg;

	espace = va_arg(arg, int);
	zeros = va_arg(arg, int);
	valofarg = va_arg(arg, int);
	size = ft_strlen(ft_itoa(valofarg));
	ft_addespace((espace - zeros), ' ', val);
	ft_addespace((zeros - size), '0', val);
	ft_putstr(ft_decimaltoupperx(valofarg), val);
}

void    ft_double_star_u(va_list arg, t_print *val)
{
	int		espace;
	int 	zeros;
	int 	size;
	int		valofarg;

	espace = va_arg(arg, int);
	zeros = va_arg(arg, int);
	valofarg = va_arg(arg, int);
	if (valofarg < 10)
	{
		size = 10;
		zeros = 10;
	}
	else
		size = ft_strlen(ft_itoa(valofarg));
	ft_addespace((espace - zeros), ' ', val);
	ft_addespace((zeros - size), '0', val);
	ft_putunsignednbr(valofarg, val);
}

void    ft_double_star_c(va_list arg, t_print *val)
{
	int espace;
	int zeros;
	char valofarg;

	espace = va_arg(arg, int);
	zeros = va_arg(arg, int);
	valofarg = va_arg(arg, int);
	ft_addespace((espace - 1), ' ', val);
	ft_putchar(valofarg, val);
}

void    ft_double_star_percent(va_list arg, t_print *val)
{
	int espace;
	int zeros;
	char valofarg;

	espace = va_arg(arg, int);
	zeros = va_arg(arg, int);
	valofarg = '%';
	ft_addespace((espace - 1), ' ', val);
	ft_putchar(valofarg, val);
}

void    ft_double_star_p(va_list arg, char *s, t_print *val)
{
	int espace;
	int zeros;
	int size;
	char *valofarg;

	espace = va_arg(arg, int) - 2;
	zeros = va_arg(arg, int);
	valofarg = ft_pointer_flags(va_arg(arg, void *), val);
	size = ft_strlen(valofarg);
	ft_addespace((espace - zeros), ' ', val);
	ft_putstr("0x", val);
	ft_addespace((zeros - size), '0', val);
	ft_putstr(valofarg, val);
	free(valofarg);
}