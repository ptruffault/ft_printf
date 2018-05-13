#include "../includes/ft_printf.h"

char	*add_value(char *format ,char *str, int *i, int *j, va_list *ap)
{
	t_param param;
	char *ret;

	if (init(&param, &format[*i + 1]) != 0)
		return (NULL);
	if (get_value(&param, ap) == -1)
	{
		error("impossible to get value", NULL);
		return (NULL);
	}
	*i = *i + next_word(&format[*i]);
	*j = *j + ft_strlen(param.value);
	if (!(ret = ft_strjoin_fr(str, param.value)))
		return (NULL);
	return (ret);
}

char *ft_vsprintf(char *format, va_list *ap)
{
	int i;
	int j;
	char *ret;

	i = 0;
	j = 0;
	if (!(ret = ft_strnew(1)))
		return (NULL);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (!(ret = add_value(format, ret, &i, &j, ap)))
				return (NULL); 
		}
		else
		{
			if (!(ret = ft_realloc(ret, j + 1, j + 2)))
				return (NULL);
			ret[j++] = format[i++];
		}
	}
	ret[j + 1] = '\0';
	return (ret);
}


int ft_printf(char *format, ...)
{
	va_list ap;
	char *tmp;
	int ret;

	va_start(ap, format);
	if (!(tmp = ft_vsprintf(format, &ap)))
	{
		error("impossible to get the output string", "(ft_sprintf)");
		return (-1);	
	}
	ret = ft_strlen(tmp);
	ft_putstr(tmp);
	free(tmp);
	va_end(ap);
	return (ret);
}

int main(void)
{
	ft_printf("%.5i", -767);
	return (0);
}