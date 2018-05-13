#include "../../includes/ft_printf.h"

static int ft_strnbr_char(char *str, char c)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			n++;
		i++;
	}
	return (n);
}

//retoune un str privé de tout les char c
char *ft_strdel_char(char *str, char c)
{
	char *new;
	int nbr;
	int i;
	int j;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	if ((nbr = ft_strnbr_char(str, c) == 0))
		return (str);
	if (!(new = ft_strnew(ft_strlen(str) - nbr)))
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] != c)
			new[j++] = str[i++];
		else
			i++;
	}
	ft_free(str);
	return (new);
}