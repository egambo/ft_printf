#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	*str = "hello";
	int		n = -123;
	unsigned int u = 4294967295;
	char	c = 'A';

	ft_printf("FT_PRINTF              |");
	printf("PRINTF:\n");
	printf("________________________________________________\n");
	ft_printf("String: %s          |", str);
	printf("String: %s\n", str);
	ft_printf("Int: %d              |", n);
	printf("Int: %d\n", n);
	ft_printf("Unsigned: %u   |", u);
	printf("Unsigned: %u\n", u);
	ft_printf("Hex x: %x        |", u);
	printf("Hex x: %x\n", u);
	ft_printf("Hex X: %X        |", u);
	printf("Hex X: %X\n", u);
	ft_printf("Pointer: %p      |", str);
	printf("Pointer: %p\n", str);
	ft_printf("Percent: %%             |");
	printf("Percent: %%\n");
	ft_printf("Char: %c                |", c);
	printf("Char: %c\n", c);
	
	int ret_ft;
	int ret_pr;
	
	printf("\n--------------------------------------------------------\n");
	ret_pr = printf("String de teste para medir o return das funções\n");
	ret_ft = ft_printf("String de teste para medir o return das funções\n");
	printf("\n");

	printf("Return do printf:    %d\n", ret_pr);
	ft_printf("Return do ft_printf: %d\n", ret_ft);
printf("--------------------------------------------------------\n");
}
