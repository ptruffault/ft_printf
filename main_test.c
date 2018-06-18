#include "includes/ft_printf.h"


int main(void)
{

	int i = 42;
	ft_printf("|%i|\n", i);
	printf("|%i|\n\n", i);

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

	ft_printf("|%D|\n", li);
	printf("|%D|\n\n",li );
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

	ft_printf("|%X|\n", i);
	printf("|%X|\n\n",i );

	char c = '$';
	ft_printf("|%c|\n", c);
	printf("|%c|\n\n",c );
	
	wchar_t C = "é";
	ft_printf("|%C|\n", C);
	printf("|%C|\n\n",C );	





	return 0;
}