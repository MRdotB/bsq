#include "header.h"

void	ft_putchar_err(char c)
{
	write(2, &c, 1);
}

void	ft_putstr_err(char *str)
{
	while(*str)
		ft_putchar_err(*str++);
	ft_putchar_err('\n');
}
