#include "../../includes/ft_printf.h"


static int ft_tools_2(char *src)
{
	int i;

	i = 0;
	while (ft_isdigit(src[i]))
			i++;
	return (i);
}

static t_param *ft_read(char *ptr, t_param *p)
{
	int i;

	i = 0;
	while ((ft_strchr("#0 +-", ptr[i])))
		p->flag = ft_stradd_char(p->flag, ptr[i++]);
	p->width = (ft_isdigit(ptr[i]) ? ft_atoi(&ptr[i]) : p->width);
	i = i + ft_tools_2(&ptr[i]);
	if (ptr[i] == '.')
	{
		while (ptr[i] == '.' )
			i++;
		p->precision = (ft_isdigit(ptr[i]) ? ft_atoi(&ptr[i]) : 0);
		i = i + ft_tools_2(&ptr[i]);
	}
	while ((ft_strchr("lhjtz", ptr[i])))
		p->length = ft_stradd_char(p->length, ptr[i++]);
	p->spec = (TEST_SPEC(ptr[i]) ? ptr[i++] : '?');
	p->opts_len = p->opts_len + i + (p->spec == '?' ? 0 : 1);
	return (p);
}





t_param 	*read_option(char *format, va_list *ap, t_param *p)
{
	if (!TEST(*(format + 1)))
	{
		p->opts_len = 1;
		return (p);
	}
	while (p->spec == '?' && TEST(*(format + 1 + p->opts_len)))
	{
		p = ft_read(format + 1 + p->opts_len, p);
		//	printf("flag = %s\nlenght = %s\n spec = %c\npreci = %i\nwidth = %i\nopts_len = %i\n",p->flag, p->length, p->spec , p->precision , p->width, p->opts_len);
	}
	p->value = (p->spec != '?' ? get_value(p, ap) : NULL);
	p->var_len = ft_strlen(p->value) + p->exep;
	return (p);
}
