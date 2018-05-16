#include "../includes/ft_printf.h"

wchar_t	*ft_wstrnew(int n)
{
	size_t	i;
	wchar_t	*new;

	i = 0;
	if (!(new = (wchar_t *)malloc(sizeof(wchar_t) * size + 1)))
		return (NULL);
	while (i <= size)
		new[i++] = '\0';
	return (new);
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
	ft_printf("test = %#8.3lld %X work", -42, 42);
	return 0;
}