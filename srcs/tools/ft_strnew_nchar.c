#include "../../includes/ft_printf.h"

//crée une chaine de caratére avec n* le char c
char *ft_strnew_nchar(char c, int n)
{
	char *new;
	int i;

	i = 0;
	if (!(new = ft_strnew(n + 1)))
		return (NULL);
	while (i < n)
		new [i++] = c;
	new[i] = '\0';
	return (new);
}