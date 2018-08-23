#include "../../includes/ft_printf.h"

static char *ft_tools(char *src, char *elem)
{
	int i;

	i = 0;
	while (ft_strchr(elem, src[i]))
		i++;
	return (ft_strndup(src, i));
}

static int ft_tools_2(char *src)
{
	int i;

	i = 0;
	while (ft_isdigit(src[i]))
			i++;
	return (i);
}

t_param 	*read_option(char *format, t_param *p)
{
	char *ptr;

	p->flag = ft_tools(format, "#0 +-");
	ptr = format + ft_strlen(p->flag);
	p->width = (ft_isdigit(*ptr) ? ft_atoi(ptr) : p->width);
	ptr = ptr + ft_tools_2(ptr);
	p->precision = (*ptr == '.' && ft_isdigit(*(ptr + 1)) ? ft_atoi(++ptr) : p->precision);
	ptr = ptr + ft_tools_2(ptr);
	p->length = ft_tools(format, "lhjtz");
	ptr = ptr + ft_strlen(p->length);
	p->spec = (TEST_SPEC(*ptr) ? *ptr : '?');
	p->opts_len = (ptr - format) + 1;
	return (p);
}
