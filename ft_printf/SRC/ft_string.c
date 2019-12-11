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

void ft_call_point_s(va_list arg, char *s)
{
    int size;
    int size1;
    int i;
    int j;
    char *valofarg;

    i = -1;
    j = 0;
    valofarg = va_arg(arg, char *);
    size1 = ft_numberofzeros(valofarg, s);
    while (s[j] != '.')
        j++;
    j++;
    size = ft_atoi((s + j));
    if (valofarg == NULL)
        ft_putstr("(null)");
    ft_addespace(size1 + size, '0');
    while (size-- != 0 && valofarg[++i] != '\0')
        ft_putchar(valofarg[i]);
}
