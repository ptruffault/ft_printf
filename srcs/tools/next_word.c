#include "../../includes/ft_printf.h"


//compte le nb de caractéres jusq'a la fin du prochain mot
int 	next_word(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\t' && str[i] != '\n' && str[i] != '\v'
	&& str[i] != '\f' && str[i] != '\r' && str[i] != ' '
	&& str[i] != '\0')
		i++;
	return (i);
}