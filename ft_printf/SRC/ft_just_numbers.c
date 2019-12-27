/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_just_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 03:29:24 by mbari             #+#    #+#             */
/*   Updated: 2019/12/25 03:29:26 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/libftprintf.h"

void	ft_double_numbers(va_list arg, char *s, t_print *val)
{
	int		espace;
	int		zeros;
	int		skip;
	t_args	value;

	espace = ft_atoi(s);
	skip = ft_skip_number(s);
	zeros = ft_atoi(s + skip + 1);
	value = ft_arg(arg, val);
	if (value.number < 0 && val->type != 'u')
		return (ft_double_number_neg(espace, zeros, &value, val));
	else if (value.number == 0 && zeros == 0)
	{
		if (espace < 0)
			espace *= -1;
		return (ft_addespace(espace, ' ', val));
	}
	else if (val->type == 's')
		return (ft_double_number_s(espace, zeros, &value, val));
	skip = ft_value_len(&value, val);
	(skip > zeros) ? (zeros = skip) : (zeros);
	ft_addespace(espace - zeros, ' ', val);
	ft_addespace(zeros - skip, '0', val);
	ft_print_arg(&value, val);
	if (espace < 0)
		ft_addespace((-espace) - zeros, ' ', val);
}

void	ft_double_number_neg(int espace, int zeros, t_args *value, t_print *val)
{
	int		size;

	size = ft_value_len(value, val);
	if (val->type == 'd' || val->type == 'i')
	{
		size--;
		espace--;
		ft_addespace(espace - zeros, ' ', val);
		ft_putchar('-', val);
		ft_addespace(zeros - size, '0', val);
		ft_putnbr(-value->number, val);
	}
	if (espace < 0)
		ft_addespace((-espace) - zeros, ' ', val);
}

void	ft_double_number_s(int espace, int zeros,
			t_args *valofarg, t_print *val)
{
	int		size;
	char	*str;

	str = valofarg->string;
	size = 0;
	if (str == NULL)
	{
		str = "(null)";
		size = ft_strlen(str);
		if (espace < zeros)
			ft_addespace(espace - size, ' ', val);
		ft_addespace(espace - zeros, ' ', val);
		ft_print_string(zeros, str, val);
	}
	else if (str[0] == '\0')
		ft_addespace(espace, ' ', val);
	else
	{
		size = ft_strlen(str);
		if (size < zeros)
			zeros = size;
		ft_addespace(espace - zeros, ' ', val);
		ft_print_string(zeros, str, val);
	}
	(zeros > size) ? (zeros = size) : (zeros);
	if (espace < 0)
		ft_addespace((-espace) - zeros, ' ', val);
}

int		ft_skip_number(char *s)
{
	int		skip;

	skip = ft_strlen(ft_itoa(ft_atoi(s)));
	if (*s == '0')
		skip++;
	return (skip);
}
