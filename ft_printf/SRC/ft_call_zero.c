/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_zero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 01:03:50 by mbari             #+#    #+#             */
/*   Updated: 2019/12/09 01:03:51 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/libftprintf.h"

void	ft_call_zero_s(va_list arg, char *s, t_print *val)
{
	int		size;
	char	*valofarg;

	size = 0;
	valofarg = va_arg(arg, char *);
	if (valofarg == NULL)
		ft_putstr("(null)", val);
	size = ft_atoi(s) - ft_strlen(valofarg);
	ft_addespace(size, '0', val);
	ft_putstr(valofarg, val);
}

void	ft_call_zero_c(va_list arg, char *s, t_print *val)
{
	int		size;
	char	c;

	size = 0;
	c = va_arg(arg, int);
	size = ft_atoi(s) - 1;
	ft_addespace(size, '0', val);
	ft_putchar(c, val);
}

void	ft_call_zero_d_i(va_list arg, char *s, t_print *val)
{
	int		size;
	int		valofarg;

	size = 0;
	valofarg = va_arg(arg, int);
	size = ft_atoi(s) - ft_strlen(ft_itoa(valofarg));
	if (valofarg < 0)
	{
		ft_putchar('-', val);
		valofarg *= -1;
	}
	if (valofarg > 0)
	{
		ft_addespace(size, '0', val);
		ft_putnbr(valofarg, val);
	}
}

void	ft_call_zero_u(va_list arg, char *s, t_print *val)
{
	int		size;
	int		test;
	int		valofarg;

	size = 0;
	valofarg = va_arg(arg, int);
	if (valofarg < 0)
		test = 10;
	else
		test = ft_strlen(ft_itoa(valofarg));
	size = ft_atoi(s) - test;
	ft_addespace(size, '0', val);
	ft_putunsignednbr(valofarg, val);
}

void	ft_call_zero_x(va_list arg, char *s, t_print *val)
{
	int		size;
	char	*valofarg;

	size = 0;
	valofarg = ft_decimaltolowerx(va_arg(arg, int));
	size = ft_atoi(s) - ft_strlen(valofarg);
	ft_addespace(size, '0', val);
	ft_putstr(valofarg, val);
	free(valofarg);
}

void	ft_call_zero_X(va_list arg, char *s, t_print *val)
{
	int		size;
	char	*valofarg;

	size = 0;
	valofarg = ft_decimaltoupperx(va_arg(arg, int));
	size = ft_atoi(s) - ft_strlen(valofarg);
	ft_addespace(size, '0', val);
	ft_putstr(valofarg, val);
	free(valofarg);
}

void	ft_call_zero_p(va_list arg, char *s, t_print *val)
{
	int		size;
	char	*valofarg;

	size = 0;
	valofarg = ft_pointer_flags(va_arg(arg, void *), val);
	size = ft_atoi(s) - ft_strlen(valofarg) - 2;
	ft_putstr("0x", val);
	ft_addespace(size, '0', val);
	ft_putstr(valofarg, val);
	free(valofarg);
}

void	ft_call_zero_percent(char *s, t_print *val)
{
	int		size;
	char	percent;

	size = 0;
	percent = '%';
	size = ft_atoi(s) - 1;
	ft_addespace(size, '0', val);
	ft_putchar(percent, val);
}
