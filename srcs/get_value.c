#include "../includes/ft_printf.h"

char	*get_value(t_param *p, va_list *ap)
{
	if (p->spec == 'd' || p->spec == 'i' || p->spec == 'o'
	|| p->spec == 'u' || p->spec == 'x' || p->spec == 'X')
		return (get_dioux(p, ap));
	return (NULL);
}