/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimaltohexadecimal.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 00:55:24 by mbari             #+#    #+#             */
/*   Updated: 2019/12/09 00:55:26 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/libftprintf.h"

char *ft_decimaltoHEX(int dic)
{
	char *hexadecimal;
	int i;
	int rest;

	i = 0;
    hexadecimal = (char *)malloc(sizeof(char) * 100);
	while (dic != 0)
	{
		rest = (dic % 16);
		if (rest < 10)
			hexadecimal[i] = rest + 48;
		else
			hexadecimal[i] = rest + 55;
		dic = dic / 16;
		i++;
	}
	hexadecimal[i] = '\0';
	ft_strrev(hexadecimal);
    return (hexadecimal);
}

char *ft_decimaltohex(int dic)
{
	char *hexadecimal;
	int i;
	int rest;


	i = 0;
    hexadecimal = (char *)malloc(sizeof(char) * 100);
	while (dic != 0)
	{
		rest = (dic % 16);
		if (rest < 10)
			hexadecimal[i] = rest + 48;
		else
			hexadecimal[i] = rest + 87;
		dic = dic / 16;
		i++;
	}
	hexadecimal[i] = '\0';
    ft_strrev(hexadecimal);
    return (hexadecimal);
}

char *ft_addriss(int dic)
{
	char *addriss;
	int i;
	int rest;


	i = 0;
    addriss = (char *)malloc(sizeof(char) * 100);
	while (dic != 0)
	{
		rest = (dic % 16);
		if (rest < 10)
			addriss[i] = rest + 48;
		else
			addriss[i] = rest + 87;
		dic = dic / 16;
		i++;
	}
	addriss[i] = '\0';
    ft_strrev(addriss);
	return (addriss);
}

void  ft_print_hex(const char *s, int dic)
{
	char *ptr;

	if (ft_check_arg(s) == 'p')
	{
		ptr = ft_addriss(dic);
		ft_putstr("0x7fff");
	}
    else if (ft_check_arg(s) == 'x')
        ptr = ft_decimaltohex(dic);
    else if (ft_check_arg(s) == 'X')
        ptr = ft_decimaltoHEX(dic);
	ft_putstr(ptr);
	free(ptr);
}