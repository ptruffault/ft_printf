#include "includes/ft_printf.h"

/*
# 0142 (signed char)
  ft_printf("%hhd", 128);
  1. (    3) -->128<--
  2. (    4) -->-128<--

# 0144 (signed char)
  ft_printf("%hhd", -129);
  1. (    4) -->-129<--
  2. (    3) -->127<--
*/
int main(void)
{
  ft_printf("%%%", "test");
  printf("%%%", "test");
 //printf("%%%\n", "test");
	return 0;
}