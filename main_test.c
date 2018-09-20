#include "includes/ft_printf.h"
#include <limits.h>
 

int main(void)
{
	printf("{%-15Z}", 123);
	ft_printf("{%-15Z}", 123);
//ft_printf("%hhu / %hhu", SHRT_MAX - 42, SHRT_MAX - 4200);
	//ft_printf("%i", 42);
//	ft_printf("%hhi", 1);
//  ft_printf("% hZ\n");
 // printf("% hZ\n");
 // ft_printf("% hZ%\n");
  //ft_printf("% Z\n", "test");
  //ft_printf("% Z \n", "test");

	return 0;
}