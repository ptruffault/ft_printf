#include "../includes/ft_printf.h"

void	ft_update_param(t_param *param)
{
	if (param->sign == '?' && ALL_NUM(param->type))
	{
		printf("lol = %s\n", param->flag);
		if (*param->value == '-')
		{
			if (!(param->value = ft_strdel_char(param->value, '-')))
				error("negative crash", "(ft_update_param)");
			param->sign = '-';
		}
		else if (param->flag != NULL && ft_strchr(param->flag, '+'))
			param->sign = '+';
	}
	param->var_len = ft_strlen(param->value);
}
//renvoi une str en fct du type de t_param
char *ft_get_ap_value(t_param *param, va_list *ap)
{
	char *ret;

	ret = NULL;
	if (param->type == 'i')
		ret = ft_itoa(va_arg(*ap, int));
	if (param->type == 's')
		ret = ft_strdup(va_arg(*ap, char*));
	if (param->type == 'c')
		ret = ft_stradd_char(ret, va_arg(*ap, int));
	ft_update_param(param);
	return(ret);
}

//car about width and precision
int	get_value(t_param *param, va_list *ap)
{
	char *tmp;
	int var_len;

	tmp =NULL;
	if (!(param->value = ft_get_ap_value(param, ap)))
		return (-1);
	var_len = ft_strlen(param->value);
	if (param->precision != -1)
	{
		if (ALL_NUM(param->type) && var_len < param->precision)
		{
			if (!(tmp = ft_strnew_nchar('0', param->precision - var_len)))
				return (-1);
			if (!(param->value = ft_strjoin_fr(tmp, param->value)))	
				return (-1);
			printf("before ?\n");
			if (param->sign != '?' && 
			!(param->value = ft_strjoin_fr(char_to_str(param->sign), param->value)))
					return (-1);

		}
		else
			param->value = ft_strndup_fr(param->value, param->precision);
	}
	var_len = ft_strlen(param->value);
	if (var_len < param->width)
	{
		if (!(tmp = ft_strnew_nchar(' ', param->width - var_len)))
			return (-1);
		if (!(param->value = ft_strjoin_fr(tmp, param->value)))
			return (-1);
	}
	return (0);
}

