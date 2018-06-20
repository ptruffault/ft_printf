#include "includes/ft_printf.h"


int main(void)
{

	int i = 42;
	ft_printf("|%5.4x|\n", i);


ft_printf("|%d|\n", i);
	printf("|%d|\n\n", i);

	long int li = 42;
	ft_printf("|%li|\n", li);
	printf("|%li|\n\n", li);

	char *s = "42";
	ft_printf("|%s|\n", s);
	printf("|%s|\n\n", s);

	ft_printf("|%p|\n", s);
	printf("|%p|\n\n",s);

	char *s1 = "0123456789";
	ft_printf("|%20.5s|\n",s1);
	printf("|%20.5s|\n\n",s1 );

	ft_printf("|%%|\n");
	printf("|%%|\n\n");

	ft_printf("|%% %i %s %p|\n", 42, s, s);
	printf("|%% %i %s %p|\n\n", 42, s, s);

	wchar_t *S = L"é$£$¤*µ²";
	ft_printf("|%S|\n",S);
	printf("|%S|\n\n", S);

	ft_printf("|%D|\n", i);
	printf("|%D|\n\n",i );
// TEST FAUX 


	ft_printf("|%o|\n", i);
	printf("|%o|\n\n",i );

	ft_printf("|%O|\n", i);
	printf("|%O|\n\n",i );

	ft_printf("|%u|\n", i);
	printf("|%u|\n\n",i );

	ft_printf("|%U|\n", i);
	printf("|%U|\n\n",i );

	ft_printf("|%x|\n", i);
	printf("|%x|\n\n",i );
/*	
	ft_printf("|%X|\n", i);
	printf("|%X|\n\n",i );

	char c = '$';
	ft_printf("|%c|\n", c);
	printf("|%c|\n\n",c );
	


	wchar_t C = L'é';
	ft_printf("|%C|\n", C);
	printf("|%C|\n\n",C );
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

	*/
	return 0;
}