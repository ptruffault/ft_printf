#include "../includes/ft_printf.h"

char	*my_strjoin(char *s1, char *s2)
{
	if (!s1 && s2)
		return (s2);
	if (s1 && !s2)
		return (s1);
	return (ft_strjoin_fr(s1, s2));
}

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

void	ft_freenstrarr(char **arr, int n)
{
	int i;

	i = 0;
	while (i < n)
		ft_strdel(&arr[i++]);
	free(arr);
	arr = NULL;
}

char	*ft_strndup_fr(char *str, int n)
{
	char *new;
	int i;

	i = 0;
	if (n < 1)
		return (str);
	if (!(new = ft_strnew(n + 1)))
		return (NULL);
	while (i < n)
	{
		new[i] = str[i]; 
		i++;
	}
	ft_strdel(&str);
	return (new);
}