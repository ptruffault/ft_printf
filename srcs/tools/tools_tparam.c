#include "../../includes/ft_printf.h"

char *ft_flag(t_param *param, char *ptr)
{
	while(*ptr == '-' || *ptr == '+' || *ptr == ' ' 
	|| *ptr == '0' || *ptr == '#')
	{
		if (!(param->flag = ft_stradd_char(param->flag, *ptr)))
			return (NULL);
		ptr++;
	}
	return (ptr);
}


char *ft_width(t_param *param, char *ptr)
{
	if (ft_isdigit(*ptr))
	{
		param->width = ft_atoi(ptr);
		while (ft_isdigit(*ptr))
			ptr++;
	}
	return (ptr);
}

char *ft_length(t_param *param, char *ptr)
{
	while ((*ptr == 'h' || *ptr == 'l' || *ptr == 'z' || *ptr == 'j'))
	{
		if (!(param->length = ft_stradd_char(param->length, *ptr)))
			return (NULL);
		ptr++;
	}	
	return (ptr);
}

char *ft_strndup_fr(char *str, int n)
{
	char *ret;

	if (!(ret = ft_strnew(n + 1)))
		return (NULL);
	ret = ft_strncpy(ret, str, n);
	ft_free(str);
	return (ret);
}

char *ft_precision(t_param *param, char *ptr)
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


char *ft_modifier(t_param *param, char *ptr)
{
	if ((*ptr == 's' || *ptr == 'S' || *ptr == 'p' || *ptr == 'd' || *ptr == 'D' ||
	*ptr == 'i' || *ptr == 'o' || *ptr == 'O' || *ptr == 'u' || *ptr == 'U' ||
	*ptr == 'x' || *ptr == 'X' || *ptr == 'c' || *ptr == 'C')
	&& (ft_is_space(*(ptr + 1)) == 1 || *(ptr + 1) == '\0'))
		param->type = *ptr;
	else
	{
		error("param must end with a type convertion modifier followed by a space", NULL);
		return (NULL);
	}	
	return (ptr);	
}