/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_and_star.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 16:07:21 by mbari             #+#    #+#             */
/*   Updated: 2019/12/20 16:07:22 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/libftprintf.h"

void    ft_one_number_s(va_list arg, char *s, t_print *val)
{
	int espace;
	int numberofchar;
	int i;
	char *valofarg;

	espace = ft_atoi(s);
	numberofchar = va_arg(arg, int);
	valofarg = va_arg(arg, char *);
	if (valofarg == NULL)
		valofarg = "(null)";
	i = 0;
	ft_addespace((espace - numberofchar), ' ', val);
	while (numberofchar != 0 && valofarg[i] != '\0')
	{
		ft_putchar(valofarg[i], val);
		numberofchar--;
		i++;
	}
}

void    ft_one_number_d_i(va_list arg, char *s, t_print *val)
{
	int espace;
	int zeros;
	int size;
	int valofarg;

	zeros = va_arg(arg, int);
	espace = ft_atoi(s);
	valofarg = va_arg(arg, int);
	if (valofarg < 0)
	{
		valofarg *= -1;
		espace--;
		ft_addespace(espace - zeros, ' ', val);
		ft_putchar('-', val);
	}
	else
		ft_addespace(espace - zeros, ' ', val);
	size = ft_strlen(ft_itoa(valofarg));
	ft_addespace((zeros - size), '0', val);
	ft_putnbr(valofarg, val);
}

void    ft_one_number_hex(va_list arg, char *s, t_print *val)
{
	int espace;
	int zeros;
	int size;
	int valofarg;

	zeros = va_arg(arg, int);
	espace = ft_atoi(s);
	valofarg = va_arg(arg, int);
	size = ft_strlen(ft_itoa(valofarg));
	ft_addespace((espace - zeros), ' ', val);
	ft_addespace((zeros - size), '0', val);
	ft_print_hex(s, va_arg(arg, int), val);
}

void    ft_one_number_u(va_list arg, char *s, t_print *val)
{
	int		espace;
	int 	zeros;
	int 	size;
	int		valofarg;

	zeros = va_arg(arg, int);
	espace = ft_atoi(s);
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

void    ft_one_number_c(va_list arg, char *s, t_print *val)
{
	int espace;
	int zeros;
	char valofarg;

	espace = ft_atoi(s);
	zeros = va_arg(arg, int);
	valofarg = va_arg(arg, int);
	ft_addespace((espace - 1), ' ', val);
	ft_putchar(valofarg, val);
}

void    ft_one_number_percent(va_list arg, char *s, t_print *val)
{
	int espace;
	int zeros;
	char valofarg;

	espace = ft_atoi(s);
	zeros = va_arg(arg, int);
	valofarg = '%';
	ft_addespace((espace - 1), ' ', val);
	ft_putchar(valofarg, val);
}

void    ft_one_number_p(va_list arg, char *s, t_print *val)
{
	int espace;
	int zeros;
	int size;
	char *valofarg;

	zeros = va_arg(arg, int);
	espace = ft_atoi(s) - 2;
	valofarg = ft_pointer(va_arg(arg, void *), val);
	size = ft_strlen(valofarg);
	ft_addespace((espace - zeros), ' ', val);
	ft_putstr("0x", val);
	ft_addespace((zeros - size), '0', val);
	ft_putstr(valofarg, val);
	free(valofarg);
}