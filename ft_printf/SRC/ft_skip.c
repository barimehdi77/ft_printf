
#include "../includes/libftprintf.h"

int ft_skip(char *s)
{
	int i;

	i = 0;
	while (s[i] != 'c' && s[i] != 's' &&  s[i] != 'p' && s[i] != 'd' && s[i] != 'i' && s[i] != 'u' && s[i] != 'x' && s[i] != 'X' && s[i] != '%')
		i++;
	return (i);
}