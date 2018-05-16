#include "../includes/ft_printf.h"

void 	raz_param(t_param *param)
{
	param->flag = NULL;
	param->width = 0;
	param->precision = -1;
	param->spec = '?';
	param->signe = '?';
	param->var_len = -1;
	param->value = NULL;
	param->elen = off;
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
	ft_free(param.flag);
	raz_param(&param);
	return (ret);
}
