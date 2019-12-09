#include "../libft/libft.h"
#include "../includes/libftprintf.h"

void ft_call_left_s(va_list arg, char *s)
{
    int size;
    char *valofarg;

    size = 0;
    valofarg = va_arg(arg, char *);
    if (valofarg == NULL)
        ft_putstr("(null)");
    size = -(ft_atoi(s) + ft_strlen(valofarg));
    ft_putstr(valofarg);
    ft_addespace(size, ' ');
}

void ft_call_left_c(va_list arg, char *s)
{
    int size;
    char c;

    size = 0;
    c = va_arg(arg, int);
    size = -(ft_atoi(s) + 1);
    ft_putchar(c);
    ft_addespace(size, ' ');
}

void ft_call_left_number(va_list arg, char *s)
{
    int size;
    int valofarg;

    size = 0;
    valofarg = va_arg(arg, int);
    size = -(ft_atoi(s) + ft_strlen(ft_itoa(valofarg)));
    ft_putnbr(valofarg);
    ft_addespace(size, ' ');
}

void ft_call_left_x(va_list arg, char *s)
{
    int size;
    char *valofarg;

    size = 0;
    valofarg = ft_decimaltohex(va_arg(arg, int));
    size = -(ft_atoi(s) + ft_strlen(valofarg));
    ft_putstr(valofarg);
    ft_addespace(size, ' ');
}

void ft_call_left_X(va_list arg, char *s)
{
    int size;
    char *valofarg;

    size = 0;
    valofarg = ft_decimaltoHEX(va_arg(arg, int));
    size = -(ft_atoi(s) + ft_strlen(valofarg));
    ft_putstr(valofarg);
    ft_addespace(size, ' ');
}

void ft_call_left_p(va_list arg, char *s)
{
    int size;
    char *valofarg;

    size = 0;
    valofarg = ft_addriss(va_arg(arg, int));
    size = -(ft_atoi(s) + ft_strlen(valofarg) + 6);
    ft_putstr("0x7fff");
    ft_putstr(valofarg);
    ft_addespace(size, ' ');
}

void ft_call_left_percent(char *s)
{
    int size;
    char percent;

    size = 0;
    percent = '%';
    size = -(ft_atoi(s) + 1);
    ft_putchar(percent);
    ft_addespace(size, ' ');
}
