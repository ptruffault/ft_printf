#include "../includes/ft_printf.h"

char	*ft_strmap_i(char const *s, int (*f)(int))
{
	char	*new;
	int		i;

	i = 0;
	new = ft_strnew(ft_strlen(s));
	if (new == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		new[i] = f(s[i]);
		i++;
	}
	return (new);
}