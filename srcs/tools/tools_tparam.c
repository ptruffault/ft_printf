#include "../../includes/ft_printf.h"

char	*ft_flag(t_param *param, char *ptr)
{
	while (*ptr == '-' || *ptr == '+' || *ptr == ' '
	|| *ptr == '0' || *ptr == '#')
	{
		if (!(param->flag = ft_stradd_char(param->flag, *ptr)))
			return (NULL);
		ptr++;
	}
	return (ptr);
}

char	*ft_width(t_param *param, char *ptr)
{
	if (ft_isdigit(*ptr))
	{
		param->width = ft_atoi(ptr);
		while (ft_isdigit(*ptr))
			ptr++;
	}
	return (ptr);
}

char	*ft_length(t_param *param, char *ptr)
{
	char *end;

	end = ptr;
	while (*end == 'h' || *end == 'l' ||
	*end == 'j' || *end == 't' || *end == 'z')
		end++;
	if (*ptr == 'h')
		param->elen = (*(ptr + 1) == 'h' ? hh : h);
	else if (*ptr == 'l')
		param->elen = (*(ptr + 1) == 'l' ? ll : l);
	else if (*ptr == 'j')
		param->elen = j;
	else if (*ptr == 'z')
		param->elen = z;
	else if (*ptr == 't')
		param->elen = t;
	return (end);
}

char	*ft_precision(t_param *param, char *ptr)
{
	if (*ptr == '.')
	{
		if (ft_isdigit(*(++ptr)))
		{
			param->precision = ft_atoi(ptr);
			while (ft_isdigit(*ptr))
				ptr++;
			return (ptr);
		}
		else if (*ptr == '-')
		{
			ptr++;
			while (ft_isdigit(*ptr))
				ptr++;
			warning("precision syntax :", ".[positif int]");
		}
		param->precision = 0;
	}
	return (ptr);
}

char	*ft_modifier(t_param *param, char *ptr)
{
	if ((*ptr == 's' || *ptr == 'S' || *ptr == 'p' || *ptr == 'd' || *ptr == 'D'
	|| *ptr == 'i' || *ptr == 'o' || *ptr == 'O' || *ptr == 'u' || *ptr == 'U'
	|| *ptr == 'x' || *ptr == 'X' || *ptr == 'c' || *ptr == 'C') || *ptr == '%')
		param->spec = *ptr;
	else
	{
		error_c("invalid type specifier :", *ptr);
		return (NULL);
	}
	return (++ptr);
}
