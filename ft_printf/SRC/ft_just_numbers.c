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

void    ft_double_numbers(va_list arg, char *s, t_print *val)
{
    int espace;
    int zeros;
    int skip;
    t_args valofarg;

    espace = ft_atoi(s);
    skip = ft_skip_number(s);
    zeros = ft_atoi(s + skip + 1);
    valofarg = ft_arg(arg, val);
    skip = ft_value_len(&valofarg, val);
    if (val->type != 's')
    {
        if (valofarg.number < 0)
            return(ft_double_number_neg(espace, zeros, &valofarg, val));
        if (valofarg.number != 0)
            (zeros < skip) ? (zeros = skip) : (zeros);
        if (val->type == 'p')
            ft_double_number_p(espace, zeros, val);
        else  
            ft_addespace(espace - zeros, ' ', val);
        ft_addespace(zeros - skip, '0', val);
        if (zeros != 0)
            ft_print_arg(&valofarg, val);
    }
    else if (val->type == 's')
        ft_double_number_s(espace, zeros, &valofarg, val);
}

void ft_double_number_neg(int espace, int zeros, t_args *value, t_print *val)
{
    int size;
    int neg;

    size = ft_value_len(value, val);
    neg = 0;
    if (value->number >= 0 || zeros == 0)
        (zeros < size) ? (neg = size) : (neg = size - zeros);
    espace--;
    ft_addespace(espace - (zeros + neg), ' ', val);
    ft_putchar('-', val);
    if (value->number < 0 && zeros == 0)
        ft_addespace(0, '0', val);
    else
        ft_addespace((zeros + neg) - size + 1, '0', val);
    value->number *= -1;
    ft_print_arg(value, val);
}

void    ft_double_number_p(int espace, int zeros, t_print *val)
{
    espace -=2;
    ft_addespace(espace - zeros, ' ', val);
    ft_putstr("0x", val);
}

void    ft_double_number_s(int espace, int zeros, t_args *valofarg, t_print *val)
{
    int size;
    char *str;

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
        return (ft_addespace(espace, ' ', val));
    else
    {
        size = ft_strlen(str);
        if (size > zeros)
            size = zeros;
        ft_addespace(espace - size, ' ', val);
        ft_print_string(zeros, str, val);
    }
}

int ft_skip_number(char *s)
{
    int skip;
    
    skip = ft_strlen(ft_itoa(ft_atoi(s)));
    return (skip);
}