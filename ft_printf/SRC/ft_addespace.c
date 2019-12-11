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
