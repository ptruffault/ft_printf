#include "../includes/ft_printf.h"

void	free_tparam(t_param *p)
{
	t_param *tmp;

	while (p)
	{
		tmp = p->next;
		ft_strdel(&p->flag);
		ft_strdel(&p->value);
		free(p);
		p = NULL;
		p = tmp;
	}
}

t_param *add_tparam(void)
{
	t_param *p;

	if (!(p = (t_param *)malloc(sizeof(t_param))))
		return (NULL);
	p->flag = NULL;
	p->width = 0;
	p->precision = -1;
	p->spec = '?';
	p->signe = '?';
	p->value = NULL;
	p->elen = off;
	p->var_len = 0;
	p->opts_len = 0;
	p->next = NULL;
	return (p);
}

//initialise t_param
t_param *new_tparam(char *format, va_list *ap, t_param *p)
{
	char *ptr;

	ptr = format;
	if (!(ptr = ft_flag(p, ptr))			||
	!(ptr = ft_width(p, ptr)) 				||
	!(ptr = ft_precision(p, ptr)) 			||
	!(ptr = ft_length(p, ptr)) 				|| 
	!(ptr = ft_modifier(p, ptr))			||
	!(p->value = get_value(p, ap)))
	{
		error("istruction init failed", NULL);
		return (NULL);
	}
	p->opts_len = (ptr - format) + 1;
	return (p);
}

t_param *init_tparam(char *format, va_list *ap)
{
	int i;
	t_param *p;
	t_param *tmp;

	p = add_tparam();
	tmp = p;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			tmp = new_tparam(&format[i + 1], ap, tmp);
			i = i + tmp->opts_len;
			tmp->next = add_tparam();
			tmp = tmp->next;
		}
		else
			i++;
	}
	return (p);
}