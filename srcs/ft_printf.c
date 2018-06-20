#include "../includes/ft_printf.h"

void	print(char *format, t_param *p)
{
	int i;

	i = 0;
	while (format[i] != '\0')
	{

		if  (format[i] == '%')
		{
			if (p->width > p->var_len && !TEST_FLAG('0') && !TEST_FLAG('-'))
				ft_putnchar(' ', p->width - p->var_len);
			ft_putstr(p->value);
			if (p->width > p->var_len && TEST_FLAG('-'))
				ft_putnchar(' ', p->width - p->var_len);
			i = i + p->opts_len;
			
			p = p->next;
		}
		else
			ft_putchar(format[i++]);
	}
}

int ft_printf(char *format, ...)
{
	va_list ap;
	t_param *p;

	va_start(ap, format);
	if (!(p = init_tparam(format, &ap)))
		return (-1);
	print(format, p);
	free_tparam(p);
	va_end(ap);
	return (0);
}


