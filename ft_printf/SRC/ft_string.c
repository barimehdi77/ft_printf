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

int ft_numberofzeros(char *valofarg, char *s)
{
	int size;

	size = 0;
	size = ft_atoi(s) - ft_strlen(valofarg);
	return (size);
}

void ft_call_point_s(va_list arg, char *s, t_print *val)
{
	int size;
	int size1;
	int i;
	int j;
	char *valofarg;

	i = -1;
	j = 0;
	valofarg = va_arg(arg, char *);
	if (valofarg == NULL)
		valofarg = "(null)";
	size1 = ft_numberofzeros(valofarg, s);
	while (s[j] != '.')
		j++;
	j++;
	size = ft_atoi((s + j));
	ft_addespace(size1, '0', val);
	while (size-- != 0 && valofarg[++i] != '\0')
		ft_putchar(valofarg[i], val);
}

int		ft_two_flags(char *s)
{
	int i;

	i = 0;
	while (*s != 's')
	{
		if (*s == '.')
			i++;
		s++;
	}
	return (i);
}

void	ft_call_zero_or_point_s(va_list arg, char *s, t_print *val)
{
	int		size;
	int		i;
	char	*valofarg;

	if (ft_two_flags(s) != 1)
	{
		i = -1;
		valofarg = va_arg(arg, char *);
		if (valofarg == NULL)
			valofarg = "(null)";
		size = ft_atoi((s));
		while (size-- != 0 && valofarg[++i] != '\0')
			ft_putchar(valofarg[i], val);
	}
	else
		ft_call_point_s(arg, s, val);
}