/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_left.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 15:22:21 by mbari             #+#    #+#             */
/*   Updated: 2019/12/11 15:22:22 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/libftprintf.h"

void	ft_call_left_s(va_list arg, char *s, t_print *val)
{
	int		size;
	char	*valofarg;

	size = 0;
	valofarg = va_arg(arg, char *);
	if (valofarg == NULL)
		ft_putstr("(null)", val);
	size = -(ft_atoi(s) + ft_strlen(valofarg));
	ft_putstr(valofarg, val);
	ft_addespace(size, ' ', val);
}

void	ft_call_left_c(va_list arg, char *s, t_print *val)
{
	int		size;
	char	c;

	size = 0;
	c = va_arg(arg, int);
	size = -(ft_atoi(s) + 1);
	ft_putchar(c, val);
	ft_addespace(size, ' ', val);
}

void	ft_call_left_number(va_list arg, char *s, t_print *val)
{
	int		size;
	int		valofarg;

	size = 0;
	valofarg = va_arg(arg, int);
	size = -(ft_atoi(s) + ft_strlen(ft_itoa(valofarg)));
	ft_putnbr(valofarg, val);
	ft_addespace(size, ' ', val);
}

void	ft_call_left_x(va_list arg, char *s, t_print *val)
{
	int		size;
	char	*valofarg;

	size = 0;
	valofarg = ft_decimaltolowerx(va_arg(arg, int));
	size = -(ft_atoi(s) + ft_strlen(valofarg));
	ft_putstr(valofarg, val);
	ft_addespace(size, ' ', val);
}

void	ft_call_left_X(va_list arg, char *s, t_print *val)
{
	int		size;
	char	*valofarg;

	size = 0;
	valofarg = ft_decimaltoupperx(va_arg(arg, int));
	size = -(ft_atoi(s) + ft_strlen(valofarg));
	ft_putstr(valofarg, val);
	ft_addespace(size, ' ', val);
}

void	ft_call_left_p(va_list arg, char *s, t_print *val)
{
	int		size;
	char	*valofarg;

	size = 0;
	valofarg = ft_pointer_flags(va_arg(arg, void *), val);
	size = -(ft_atoi(s) + ft_strlen(valofarg) + 2);
	ft_putstr("0x", val);
	ft_putstr(valofarg, val);
	ft_addespace(size, ' ', val);
	free(valofarg);
}

void	ft_call_left_percent(char *s, t_print *val)
{
	int		size;
	char	percent;

	size = 0;
	percent = '%';
	size = -(ft_atoi(s) + 1);
	ft_putchar(percent, val);
	ft_addespace(size, ' ', val);
}
