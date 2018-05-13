#include "../includes/ft_printf.h"

void	ft_put_param(t_param *param)
{
	if (param->type != '?')
		printf("type = %c\n", param->type);
	if (param->flag)
		printf("flag = %s\n", param->flag);
	if (param->width != 0)
		printf("width = %i\n", param->width);
	if (param->precision != 1)
		printf("precision = %i\n", param->precision);
	if (param->length)
		printf("length = %s\n", param->length);

}