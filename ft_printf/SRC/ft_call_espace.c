/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_espace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 00:20:07 by mbari             #+#    #+#             */
/*   Updated: 2019/12/09 00:20:08 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/libftprintf.h"

void	ft_call_s(va_list arg, char *s, t_print *val)
{
	int		size;
	char	*valofarg;

	size = 0;
	valofarg = va_arg(arg, char *);
	if (valofarg == NULL)
		ft_putstr("(null)", val);
	size = ft_atoi(s) - ft_strlen(valofarg);
	ft_addespace(size, ' ', val);
	ft_putstr(valofarg, val);
}

void	ft_call_c(va_list arg, char *s, t_print *val)
{
	int		size;
	char	c;

	size = 0;
	c = va_arg(arg, int);
	size = ft_atoi(s) - 1;
	ft_addespace(size, ' ', val);
	ft_putchar(c, val);
}

void	ft_call_number(va_list arg, char *s, t_print *val)
{
	int		size;
	int		valofarg;

	size = 0;
	valofarg = va_arg(arg, int);
	size = ft_atoi(s) - ft_strlen(ft_itoa(valofarg));
	ft_addespace(size, ' ', val);
	ft_putnbr(valofarg, val);
}

void	ft_call_x(va_list arg, char *s, t_print *val)
{
	int		size;
	char	*valofarg;

	size = 0;
	valofarg = ft_decimaltolowerx(va_arg(arg, int));
	size = ft_atoi(s) - ft_strlen(valofarg);
	ft_addespace(size, ' ', val);
	ft_putstr(valofarg, val);
	free(valofarg);
}

void	ft_call_p(va_list arg, char *s, t_print *val)
{
	int		size;
	char	*valofarg;

	size = 0;
	valofarg = ft_pointer_flags(va_arg(arg, void *), val);
	size = ft_atoi(s) - ft_strlen(valofarg) - 2;
	ft_addespace(size, ' ', val);
	ft_putstr("0x", val);
	ft_putstr(valofarg, val);
	free(valofarg);
}

void	ft_call_X(va_list arg, char *s, t_print *val)
{
	int		size;
	char	*valofarg;

	size = 0;
	valofarg = ft_decimaltoupperx(va_arg(arg, int));
	size = ft_atoi(s) - ft_strlen(valofarg);
	ft_addespace(size, ' ', val);
	ft_putstr(valofarg, val);
	free(valofarg);
}

void	ft_call_percent(char *s, t_print *val)
{
	int		size;
	char	percent;

	size = 0;
	percent = '%';
	size = ft_atoi(s) - 1;
	ft_addespace(size, ' ', val);
	ft_putchar(percent, val);
}
