#include "../../includes/ft_printf.h"

char *char_to_str(char c)
{
	char *new;

	if (!(new = ft_strnew(2)))
		return (NULL);
	new[0] = c;
	new[1] = '\0';
	return (new);
}