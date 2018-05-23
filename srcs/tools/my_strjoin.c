#include "../../includes/ft_printf.h"

char	*my_strjoin(char *s1, char *s2)
{
	if (!s1 && s2)
		return (s2);
	if (s1 && !s2)
		return (s1);
	return (ft_strjoin(s1, s2));
}

char  	*my_strjoin_fr(char *s1, char *s2)
{
	char *ret;

	if (!s1 && s2)
		return (s2);
	if (s1 && !s2)
		return (s1);
	if (!(ret = ft_strjoin(s1, s2)))
		return (NULL);
	free(s1);
	free(s2);
	return (ret);
}