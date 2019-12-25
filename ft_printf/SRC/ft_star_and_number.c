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

void    ft_one_star_s(va_list arg, char *s, t_print *val)
{
	int espace;
	int numberofchar;
	int i;
	char *valofarg;
	
	i = 0;
	espace = va_arg(arg, int);
	numberofchar = ft_atoi(s);
	valofarg = va_arg(arg, char *);
	if (valofarg == NULL)
		valofarg = "(null)";
	if (valofarg[0] == '\0')
		ft_addespace(espace, ' ', val);
	else
		ft_addespace((espace - numberofchar), ' ', val);
	while (numberofchar != 0 && valofarg[i] != '\0')
	{
		ft_putchar(valofarg[i], val);
		numberofchar--;
		i++;
	}
}

void    ft_one_star_d_i(va_list arg, char *s, t_print *val)
{
	int espace;
	int zeros;
	int size;
	int valofarg;

	espace = va_arg(arg, int);
	zeros = ft_atoi(s);
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

void    ft_one_star_hex(va_list arg, char *s, t_print *val)
{
	int espace;
	int zeros;
	int size;
	int valofarg;

	espace = va_arg(arg, int);
	zeros = ft_atoi(s);
	valofarg = va_arg(arg, int);
	size = ft_strlen(ft_itoa(valofarg));
	ft_addespace((espace - zeros), ' ', val);
	ft_addespace((zeros - size), '0', val);
	ft_print_hex(s, valofarg, val);
}

void    ft_one_star_u(va_list arg, char *s, t_print *val)
{
	int		espace;
	int 	zeros;
	int 	size;
	int		valofarg;

	espace = va_arg(arg, int);
	zeros = ft_atoi(s);
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

void    ft_one_star_c(va_list arg, t_print *val)
{
	int espace;
	char valofarg;

	espace = va_arg(arg, int);
	valofarg = va_arg(arg, int);
	ft_addespace((espace - 1), ' ', val);
	ft_putchar(valofarg, val);
}

void    ft_one_star_percent(va_list arg, t_print *val)
{
	int espace;
	char valofarg;

	espace = va_arg(arg, int);
	valofarg = '%';
	ft_addespace((espace - 1), ' ', val);
	ft_putchar(valofarg, val);
}

void    ft_one_star_p(va_list arg, char *s, t_print *val)
{
	int espace;
	int zeros;
	int size;
	char *valofarg;

	espace = va_arg(arg, int) - 2;
	zeros = ft_atoi(s);
	valofarg = ft_pointer(va_arg(arg, void *), val);
	size = ft_strlen(valofarg);
	ft_addespace((espace - zeros), ' ', val);
	ft_putstr("0x", val);
	ft_addespace((zeros - size), '0', val);
	ft_putstr(valofarg, val);
	free(valofarg);
}