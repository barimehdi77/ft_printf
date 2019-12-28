/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addespace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 00:16:50 by mbari             #+#    #+#             */
/*   Updated: 2019/12/28 13:23:58 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/libftprintf.h"

void	ft_addespace(int size, char c, t_print *val)
{
	if (size > 0)
	{
		while (size)
		{
			ft_putchar(c, val);
			size--;
		}
	}
}
