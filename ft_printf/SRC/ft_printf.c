/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 01:16:56 by mbari             #+#    #+#             */
/*   Updated: 2019/12/02 00:17:23 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/libftprintf.h"

void	ft_set_val(t_print *val)
{
	val->count = 0;
	val->star = 0;
}

int		ft_printf(const char *s, ...)
{
	t_print		val; 
	int			i;
	va_list		arg;

	i = -1;
	ft_set_val(&val);
	va_start(arg, s);
	while (s[++i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			if (NORMAL_FORMS)
				ft_normal_forms(arg, (char *)(s + i), &val);
			else if (FLAGS_FORMS)
				ft_flags(arg, s + i, &val);
			i += ft_skip((char *)(s + i));
		}
		else
			ft_putchar(s[i], &val);
	}
	va_end(arg);
	return (val.count);
}

int main()
{
	char c = 'M';
	ft_printf("%d\n",ft_printf("--%020p--",&"hello"));//done
	printf("%d\n",printf("--%020p--",&"hello"));
	
}