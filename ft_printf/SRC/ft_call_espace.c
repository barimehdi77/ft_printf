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

void ft_call_s(va_list arg, char *s)
{
    int size;
    char *valofarg;

    size = 0;
    valofarg = va_arg(arg, char *);
    if (valofarg == NULL)
        ft_putstr("(null)");
    size = ft_atoi(s) - ft_strlen(valofarg);
    ft_addespace(size, ' ');
    ft_putstr(valofarg);
}

void ft_call_c(va_list arg, char *s)
{
    int size;
    char c;

    size = 0;
    c = va_arg(arg, int);
    size = ft_atoi(s) - 1;
    ft_addespace(size, ' ');
    ft_putchar(c);
}

void ft_call_number(va_list arg, char *s)
{
    int size;
    int valofarg;

    size = 0;
    valofarg = va_arg(arg, int);
    size = ft_atoi(s) - ft_strlen(ft_itoa(valofarg));
    ft_addespace(size, ' ');
    ft_putnbr(valofarg);
}

void ft_call_x(va_list arg, char *s)
{
    int size;
    char *valofarg;

    size = 0;
    valofarg = ft_decimaltohex(va_arg(arg, int));
    size = ft_atoi(s) - ft_strlen(valofarg);
    ft_addespace(size, ' ');
    ft_putstr(valofarg);
}

void ft_call_p(va_list arg, char *s)
{
    int size;
    char *valofarg;

    size = 0;
    valofarg = ft_addriss(va_arg(arg, int));
    size = ft_atoi(s) - ft_strlen(valofarg) - 6;
    ft_addespace(size, ' ');
    ft_putstr("0x7fff");
    ft_putstr(valofarg);
}

void ft_call_X(va_list arg, char *s)
{
    int size;
    char *valofarg;

    size = 0;
    valofarg = ft_decimaltoHEX(va_arg(arg, int));
    size = ft_atoi(s) - ft_strlen(valofarg);
    ft_addespace(size, ' ');
    ft_putstr(valofarg);
}

void ft_call_percent(char *s)
{
    int size;
    char percent;

    size = 0;
    percent = '%';
    size = ft_atoi(s) - 1;
    ft_addespace(size, ' ');
    ft_putchar(percent);
}
