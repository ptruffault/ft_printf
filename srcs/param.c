#include "../includes/ft_printf.h"

void 	raz_param(t_param *p)
{
	p->flag = NULL;
	p->width = 0;
	p->precision = -1;
	p->spec = '?';
	p->signe = '?';
	p->var_len = -1;
	p->value = NULL;
	p->elen = off;
}

//initialise t_param
int	init(t_param *param, char *format)
{
	
	char *ptr;
	raz_param(param);

	ptr = format;
	if (!(ptr = ft_flag(param, ptr))	||
	!(ptr = ft_width(param, ptr)) 		||
	!(ptr = ft_precision(param, ptr)) 	||
	!(ptr = ft_length(param, ptr)) 		|| 
	!(ptr = ft_modifier(param, ptr)))
	{
		error("istruction init failed", NULL);
		return (-1);
	}
	return (0);
}

char	*add_value(char *format ,char *str, int *i, int *j, va_list *ap)
{
	t_param param;
	char *ret;
	char *value;

	if (init(&param, &format[*i + 1]) != 0)
		return (NULL);
	if (!(value = get_value(&param, ap)))
	{
		error("impossible to get value", NULL);
		return (NULL);
	}
	*i = *i + next_word(&format[*i]);
	*j = *j + ft_strlen(value);
	if (!(ret = ft_strjoin_fr(str, value)))
		return (NULL);
	ft_free(param.flag);
	raz_param(&param);
	return (ret);
}
