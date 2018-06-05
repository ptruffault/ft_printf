#include "includes/ft_printf.h"

int main(void)
{
	ft_printf("test de merde\n");
	   printf("test0: %#10o %10s \n", 42, "lol");
	ft_printf("test0: %#10o %10s \n", 42, "lol");
	ft_printf("  %%   \n");
	ft_printf("LOL\n");
	return 0;
}