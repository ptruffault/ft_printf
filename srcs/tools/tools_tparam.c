#include "../../includes/ft_printf.h"

static char *ft_tools(char *src, char *elem)
{
	int i;

	i = 0;
	while (ft_strchr(elem, src[i]))
		i++;
	if (i > 0)
		return (ft_strndup(src, i));
	return (NULL);
}

static int ft_tools_2(char *src)
{
	int i;

	i = 0;
	while (ft_isdigit(src[i]))
			i++;
	return (i);
}

t_param 	*read_option(char *format, va_list *ap, t_param *p)
{
	char	*ptr;

	p->signe = '?';
	p->exep = 0;
	p->var_len = 0;
	p->next = NULL;
	ptr = format + 1;
	p->flag = ft_tools(ptr, "#0 +-");
	ptr = ptr + ft_strlen(p->flag);
	p->width = (ft_isdigit(*ptr) ? ft_atoi(ptr) : 0);
	ptr = ptr + ft_tools_2(ptr);
	p->precision = (*ptr == '.' ? (ft_isdigit(*(++ptr)) ? ft_atoi(ptr) : 0) : -1);
	ptr = ptr + ft_tools_2(ptr);
	p->length = ft_tools(ptr, "lhjtz");
	ptr = ptr + ft_strlen(p->length);
	p->spec = (TEST_SPEC(*ptr) ? *ptr : '?');
	p->opts_len = (ptr - format) + (p->spec == '?' ? 0 : 1);
	p->value = (p->spec != '?' ? get_value(p, ap) : NULL);
	p->var_len = ft_strlen(p->value) + p->exep;
	return (p);
}
