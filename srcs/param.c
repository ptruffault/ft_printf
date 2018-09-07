#include "../includes/ft_printf.h"

static t_param *add_tparam(void)
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
	p->var_len = 0;
	p->opts_len = 0;
	p->next = NULL;
	return (p);
}

t_param *init_tparam(char *format, va_list *ap)
{
	int		i;
	t_param	*p;
	t_param	*tmp;

	p = add_tparam();
	tmp = p;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			tmp = read_option(&format[i], tmp);
			if (tmp->spec != '?')
				p->value = get_value(p, ap);
			i = i + tmp->opts_len;
			tmp->next = add_tparam();
			tmp = tmp->next;
		}
		else
			i++;
	}
	return (p);
}

void	free_tparam(t_param *p)
{
	t_param *tmp;

	while (p)
	{
		tmp = p->next;
		ft_strdel(&p->flag);
		ft_strdel(&p->length);
		if (p->spec != '?')
			ft_strdel(&p->value);
		free(p);
		p = NULL;
		p = tmp;
	}
}
