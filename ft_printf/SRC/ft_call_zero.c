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

void ft_call_zero_s(va_list arg, char *s)
{
    int size;
    int i;
    char *valofarg;

    i = -1;
    size = ft_atoi(s);
    valofarg = va_arg(arg, char *);
    if (valofarg == NULL)
        ft_putstr("(null)");
    while (size-- != 0 && valofarg[++i] != '\0')
        ft_putchar(valofarg[i]);
}

void ft_call_zero_c(va_list arg, char *s)
{
    int size;
    char c;

    size = 0;
    c = va_arg(arg, int);
    size = ft_atoi(s) - 1;
    ft_addespace(size, '0');
    ft_putchar(c);
}

void ft_call_zero_number(va_list arg, char *s)
{
    int size;
    int valofarg;

    size = 0;
    valofarg = va_arg(arg, int);
    size = ft_atoi(s) - ft_strlen(ft_itoa(valofarg));
    ft_addespace(size, '0');
    ft_putnbr(valofarg);
}

void ft_call_zero_x(va_list arg, char *s)
{
    int size;
    char *valofarg;

    size = 0;
    valofarg = ft_decimaltohex(va_arg(arg, int));
    size = ft_atoi(s) - ft_strlen(valofarg);
    ft_addespace(size, '0');
    ft_putstr(valofarg);
}

void ft_call_zero_X(va_list arg, char *s)
{
    int size;
    char *valofarg;

    size = 0;
    valofarg = ft_decimaltoHEX(va_arg(arg, int));
    size = ft_atoi(s) - ft_strlen(valofarg);
    ft_addespace(size, '0');
    ft_putstr(valofarg);
}

void ft_call_zero_percent(char *s)
{
    int size;
    char percent;

    size = 0;
    percent = '%';
    size = ft_atoi(s) - 1;
    ft_addespace(size, '0');
    ft_putchar(percent);
}
