#include "../../includes/ft_printf.h"


static void		f(intmax_t value, int base, char *str, int *i)
{
	char	*tmp;

	tmp = "0123456789abcdef";
	if (value <= -base || value >= base)
		f(value / base, base, str, i);
	if ((value % base) < 0)
		str[*i] = tmp[-(value % base)];
	else
		str[*i] = tmp[value % base];
	(*i)++;
}

char		*ft_itoa_base_intmax(intmax_t value, int base)
{
	int		i;
	char	*str;

	i = 0;
	if (base < 2 || base > 16 || !(str = (char*)malloc(32)))
		return (0);
	if (base == 10 && value < 0)
		str[i++] = '-';
	if (value == 0)
		return ("0");
	if (value == 1)
		return ("1");
	f(value, base, str, &i);
	str[i] = '\0';
	return (str);
}

static void		f_unintmax(uintmax_t value, unsigned int base, char *str, int *i)
{
	char	*tmp;

	tmp = "0123456789abcdef";
	if (value >= base)
		f(value / base, base, str, i);
	str[*i] = tmp[value % base];
	(*i)++;
}

char		*ft_itoa_base_unintmax(uintmax_t value, int base)
{
	int		i;
	char	*str;

	i = 0;
	if (base < 2 || base > 16 || !(str = (char*)malloc(32)))
		return (0);
	if (value == 0)
		return ("0");
	if (value == 1)
		return ("1");
	f_unintmax(value, base, str, &i);
	str[i] = '\0';
	return (str);
}


char	*ft_itoa_intmax(intmax_t n)
{
	char		*s;
	char		*rep;
	intmax_t	num;
	int			i;

	rep = "0123456789";
	if (!(s = (char *)malloc(sizeof(char) * 4)))
		return (NULL);
	i = 0;
	num = n;
	if (n < 0)
		num *= -1;
	if (n == 0)
		return ("0");
	while (num != 0)
	{
		s[i] = rep[num % 10];
		i++;
		num /= 10;
	}
	if (n < 0)
		s[i++] = '-';
	s[i] = '\0';
	return (ft_strrev(s));
}
