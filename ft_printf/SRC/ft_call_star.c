/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_star.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 15:22:38 by mbari             #+#    #+#             */
/*   Updated: 2019/12/11 15:22:40 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/libftprintf.h"

void	ft_call_star_s(va_list arg, t_print *val)
{
	int		size;
	char	*valofarg;

	size = va_arg(arg, int);
	valofarg = va_arg(arg, char *);
	if (valofarg == NULL)
		ft_putstr("(null)", val);
	size -= ft_strlen(valofarg);
	ft_addespace(size, ' ', val);
	ft_putstr(valofarg, val);
}

void	ft_call_star_c(va_list arg, t_print *val)
{
	int		size;
	char	c;

	size = va_arg(arg, int);
	c = va_arg(arg, int);
	size -= 1;
	ft_addespace(size, ' ', val);
	ft_putchar(c, val);
}

void	ft_call_star_number(va_list arg, t_print *val)
{
	int		size;
	int		valofarg;

	size = va_arg(arg, int);
	valofarg = va_arg(arg, int);
	size -= ft_strlen(ft_itoa(valofarg));
	ft_addespace(size, ' ', val);
	ft_putnbr(valofarg, val);
}

void	ft_call_star_x(va_list arg, t_print *val)
{
	int		size;
	char	*valofarg;

	size = va_arg(arg, int);
	valofarg = ft_decimaltolowerx(va_arg(arg, int));
	size -= ft_strlen(valofarg);
	ft_addespace(size, ' ', val);
	ft_putstr(valofarg, val);
	free(valofarg);
}

void	ft_call_star_p(va_list arg, t_print *val)
{
	int		size;
	char	*valofarg;

	size = va_arg(arg, int);
	valofarg = ft_pointer_flags(va_arg(arg, void *), val);
	size -= (ft_strlen(valofarg) + 2);
	ft_addespace(size, ' ', val);
	ft_putstr("0x", val);
	ft_putstr(valofarg, val);
	free(valofarg);
}

void	ft_call_star_X(va_list arg, t_print *val)
{
	int		size;
	char	*valofarg;

	size = va_arg(arg, int);
	valofarg = ft_decimaltoupperx(va_arg(arg, int));
	size -= ft_strlen(valofarg);
	ft_addespace(size, ' ', val);
	ft_putstr(valofarg, val);
	free(valofarg);
}

void	ft_call_star_percent(va_list arg, t_print *val)
{
	int		size;
	char	percent;

	size = va_arg(arg, int);
	percent = '%';
	size -= -1;
	ft_addespace(size, ' ', val);
	ft_putchar(percent, val);
}
