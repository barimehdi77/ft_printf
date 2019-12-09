/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addespace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 00:16:50 by mbari             #+#    #+#             */
/*   Updated: 2019/12/02 00:16:53 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/libftprintf.h"

void    ft_addespace(int size, char c)
{
    if (size > 0)
    {
        while (size)
        {
            ft_putchar(c);
            size--;
        }
    }
}

/*void    ft_star(va_list arg, char *s)
{
    ft_addespace(va_arg(arg, int), ' ');
    if (ft_check_arg(s) == 's')
        ft_putstr(va_arg(arg, char *));
    else if (ft_check_arg(s) == 'c')
        ft_call_c(arg, s);
    else if (ft_check_arg(s) == 'd' || ft_check_arg(s) == 'i')
        ft_call_number(arg, s);
    else if (ft_check_arg(s) == 'u')
        ft_call_number(arg, s);
    else if (ft_check_arg(s) == 'p')
        ft_call_p(arg, s);
    else if (ft_check_arg(s) == 'x')
        ft_call_x(arg, s);
    else if (ft_check_arg(s) == 'X')
        ft_call_X(arg, s);
    else if (ft_check_arg(s) == '%')
        ft_call_percent(s);
}*/