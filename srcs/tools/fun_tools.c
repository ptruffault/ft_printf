#include "../includes/ft_printf.h"


char	*my_strjoin(char *s1, char *s2)
{
	if (!s1 && s2)
		return (s2);
	if (s1 && !s2)
		return (s1);
	return (ft_strjoin_fr(s1, s2));
}

char	*ft_strmap_i(char *s, int (*f)(int))
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
	ft_strdel(&s);
	return (new);
}

char	*ft_strndup_fr(char *str, int n)
{
	char *ret;

	ret = ft_strndup(str, n);
	ft_strdel(&str);
	return (ret);
}

void	ft_putnchar(char c, int n)
{
	while (n-- > 0)
		ft_putchar(c);
}
