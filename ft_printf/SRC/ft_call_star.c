#include "../libft/libft.h"
#include "../includes/libftprintf.h"

void ft_call_star_s(va_list arg, char *s)
{
    int size;
    char *valofarg;

    size = va_arg(arg, int);
    valofarg = va_arg(arg, char *);
    if (valofarg == NULL)
        ft_putstr("(null)");
    size -= ft_strlen(valofarg);
    ft_addespace(size, ' ');
    ft_putstr(valofarg);
}

void ft_call_star_c(va_list arg, char *s)
{
    int size;
    char c;

    size = va_arg(arg, int);
    c = va_arg(arg, int);
    size -= 1;
    ft_addespace(size, ' ');
    ft_putchar(c);
}

void ft_call_star_number(va_list arg, char *s)
{
    int size;
    int valofarg;

    size = va_arg(arg, int);
    valofarg = va_arg(arg, int);
    size -= ft_strlen(ft_itoa(valofarg));
    ft_addespace(size, ' ');
    ft_putnbr(valofarg);
}

void ft_call_star_x(va_list arg, char *s)
{
    int size;
    char *valofarg;

    size = va_arg(arg, int);
    valofarg = ft_decimaltohex(va_arg(arg, int));
    size -=ft_strlen(valofarg);
    ft_addespace(size, ' ');
    ft_putstr(valofarg);
}

void ft_call_star_p(va_list arg, char *s)
{
    int size;
    char *valofarg;

    size = va_arg(arg, int);
    valofarg = ft_addriss(va_arg(arg, int));
    size -=(ft_strlen(valofarg) + 6);
    ft_addespace(size, ' ');
    ft_putstr("0x7fff");
    ft_putstr(valofarg);
}

void ft_call_star_X(va_list arg, char *s)
{
    int size;
    char *valofarg;

    size = va_arg(arg, int);
    valofarg = ft_decimaltoHEX(va_arg(arg, int));
    size -= ft_strlen(valofarg);
    ft_addespace(size, ' ');
    ft_putstr(valofarg);
}

void ft_call_star_percent(va_list arg, char *s)
{
    int size;
    char percent;

    size = va_arg(arg, int);
    percent = '%';
    size -= - 1;
    ft_addespace(size, ' ');
    ft_putchar(percent);
}