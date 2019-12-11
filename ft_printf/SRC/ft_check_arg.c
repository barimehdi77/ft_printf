/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 00:16:58 by mbari             #+#    #+#             */
/*   Updated: 2019/12/02 00:17:01 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char    ft_check_arg(const char *s)
{
    char c;

    while (*s)
    {
        s++;
        if (*s == 'c')
            return (c = *s);
        else if (*s == 's')
            return (c = *s);
        else if (*s == 'd' || *s == 'i')
            return (c = *s);
        else if (*s == 'u')
            return (c = *s);
        else if (*s == '.')
            return (c = *s);
        else if (*s == 'x')
            return (c = *s);
        else if (*s == 'X')
            return (c = *s);
        else if (*s == 'p')
            return (c = *s);
        else if (*s == '%')
            return (c = *s);
    }
    return (0);
}
