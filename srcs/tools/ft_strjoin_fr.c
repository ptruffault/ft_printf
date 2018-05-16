#include "../../includes/ft_printf.h"

char *ft_strjoin_fr(char *s1, char *s2)
{
	char *ret;

	if (!(ret = ft_strjoin(s1, s2)))
		return (NULL);
	ft_free(s1);
	ft_free(s2);
	return (ret);
}