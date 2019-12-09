/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 01:16:56 by mbari             #+#    #+#             */
/*   Updated: 2019/12/02 00:17:23 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../libft/libft.h"
#include "../includes/libftprintf.h"

int ft_printf(const char *s, ...)
{
    int i;
    va_list arg;

    i = 0;
    va_start(arg,s);
    while (s[i] != '\0')
    {
        if (s[i] == '%')
        {
            i++;
            if (*(s + i) == '%')
				ft_putchar('%');
            else if (*(s + i) == 'c')
                ft_putchar(va_arg(arg, int));
            else if (*(s + i) == 'd' || s[i] == 'i')
                ft_putnbr(va_arg(arg, int));
            else if (*(s + i) == 'u')
                ft_putunsignednbr(va_arg(arg, unsigned int));
            else if (*(s + i) == 's')
                ft_putstr(va_arg(arg, char *));
            else if (*(s + i) == 'p')
                ft_print_addriss(va_arg(arg, int));
            else if(*(s + i) == 'X')
                ft_putstr(ft_decimaltoHEX(va_arg(arg, int)));
            else if(*(s + i) == 'x')
                ft_putstr(ft_decimaltohex(va_arg(arg, int)));
            else if (ft_isdigit(*(s + i)))
                ft_check_espace(arg, (char *)s + i);
            else if (*(s + i) == '0')
                ft_check_zero(arg, (char *)s + i);
            else if (*(s + i) == '*')
                ft_check_star(arg, (char *)s + i);
            else if (*(s + i) == '-')
                ft_check_left(arg, (char *)s + i);
            else if (*(s + i) == '.')
                ft_check_point(arg, (char *)s + i + 1);
            i += ft_skip((char *)(s + i));
        }
        else
			ft_putchar(s[i]);
		i++;
    }
    va_end(arg);
    return (0);
}

int main()
{
    char c = 'M';
    ft_printf("--%-100s--\n","777777777");
    printf("--%-100s--","777777777");
}
