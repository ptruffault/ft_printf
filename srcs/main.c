#include "../includes/ft_printf.h"

char *ft_vsprintf(char *format, va_list *ap)
{
	int i;
	int j;
	char *ret;

	i = 0;
	j = 0;
	if (!(ret = ft_strnew(1)))
		return (NULL);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && !(ret = add_value(format, ret, &i, &j, ap)))
			return (NULL); 
		else
		{
			if (!(ret = ft_realloc(ret, j + 1, j + 2)))
				return (NULL);
			ret[j++] = format[i++];
		}
	}
	ret[j + 1] = '\0';
	return (ret);
}


int ft_printf(char *format, ...)
{
	va_list ap;
	char *tmp;
	int ret;

	va_start(ap, format);
	if (!(tmp = ft_vsprintf(format, &ap)))
	{
		error("impossible to get the output string", "(ft_sprintf)");
		return (-1);	
	}
	ret = ft_strlen(tmp);
	ft_putstr(tmp);
	free(tmp);
	va_end(ap);
	return (ret);
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