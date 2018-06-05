#include "../includes/ft_printf.h"

void	print(char *format, t_param *p)
{
	int i;

	i = 0;
	while (format[i] != '\0')
	{
		if  (format[i] == '%')
		{
			ft_putstr(p->value);
			i = i + p->opts_len;
			p = p->next;

		}
		else
			ft_putchar(format[i++]);
	}
}

int ft_printf(char *format, ...)
{
	va_list ap;
	t_param *p;

	va_start(ap, format);
	if (!(p = init_tparam(format, &ap)))
		return (-1);
	print(format, p);
	free_tparam(p);
	va_end(ap);
	return (0);
}



/*


int	main(void)
{


	printf("\033[01;34mTEST 1\033[00m\n");
	printf("%d\n", printf("{%c}", '$'));
	printf("%d\n", ft_printf("{%c}", '$'));
	printf("\033[1;32m%%c [OK]\n\n\33[00m\n");
	
	printf("\033[01;34mTEST 2\033[00m\n");
	printf("%d\n", printf("{%s}", "TEST De Merde :)"));
	printf("%d\n", ft_printf("{%s}", "TEST De Merde :)"));
	printf("\033[1;32m%%s [OK] :\n\n\033[00m\n");

	printf("\033[01;34mTEST 3\033[00m\n");
	printf("%d\n", printf("{%i}", 42));
	printf("%d\n", ft_printf("{%i}", 42));
	printf("\033[1;32m%%i [OK] :\n\n\033[00m\n");

	printf("\033[01;34mTEST 4\033[00m\n");
	printf("%d\n", printf("{% i}", 42));
	printf("%d\n", ft_printf("{% i}", 42));
	printf("\033[1;32m%% i [OK] :\n\n\033[00m\n");

	printf("\033[01;34mTEST 5\033[00m\n");
	printf("%d\n", printf("{%10i}", 42));
	printf("%d\n", ft_printf("{%10i}", 42));
	printf("\033[1;32m%%10i [OK] :\n\n\033[00m\n");

	printf("\033[01;34mTEST 6\033[00m\n");
	printf("%d\n", printf("{%010i}", 42));
	printf("%d\n", ft_printf("{%010i}", 42));
	printf("\033[1;32m%%010i [OK] :\n\n\033[00m\n");

	printf("\033[01;34mTEST 7\033[00m\n");
	printf("%d\n", printf("{%#10.3o}", 42));
	printf("%d\n", ft_printf("{%#10.3o}", 42));
	printf("\033[1;32m%%#10.3o [OK] :\n\n\033[00m\n");

	printf("\033[01;34mTEST 6\033[00m\n");
	printf("%d\n", printf("{%#04o}", 42));
	printf("%d\n", ft_printf("{%#04o}", 42));
	printf("\033[1;32m%%#04o [OK] :\n\n\033[00m\n");

	printf("\033[01;34mTEST 9\033[00m\n");
	printf("%d\n", printf("{%#-4x}", 42));
	printf("%d\n", ft_printf("{%#-4x}", 42));
	printf("\033[1;32m%%#-4x [OK] :\n\n\033[00m\n");

	printf("\033[01;34mTEST 10\033[00m\n");
	printf("%d\n", printf("{%#04x}", 42));
	printf("%d\n", ft_printf("{%#04x}", 42));
	printf("\033[1;32m%%#04x [OK] :\n\n\033[00m\n");

	printf("\033[01;34mTEST 11\033[00m\n");
	printf("%d\n", printf("{%#04X}", 42));
	printf("%d\n", ft_printf("{%#04X}", 42));
	printf("\033[1;32m%%#04X [OK] :\n\n\033[00m\n");
	


	return (0);

}
*/