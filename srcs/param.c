#include "../includes/ft_printf.h"

void 	raz_param(t_param *param)
{
	param->flag = NULL;
	param->width = 0;
	param->precision = -1;
	param->length = NULL;
	param->type = '?';
	param->sign = '?';
	param->var_len = -1;
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

