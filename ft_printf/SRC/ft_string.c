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

void	ft_print_string(int size, char *str, t_print *val)
{
	int i;

	i = 0;
	while (size > i && str[i] != '\0')
	{
		ft_putchar(str[i], val);
		i++;
	}
}