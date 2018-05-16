#include "../includes/ft_printf.h"








intmax_t get_signed_ent(va_list *ap, t_param *t)
{
	intmax_t ret;

	if (t->elen == hh)
		ret = va_arg(*ap, int);
	else if (t->elen == h)
		ret = (signed short int)va_arg(*ap, signed int);
	else if (t->elen == l)
		ret = (signed long int)va_arg(*ap, signed long int);
	else if (t->elen == ll)
		ret = (signed long long int)va_arg(*ap, signed long long int);
	else if (t->elen == j)
		ret = (intmax_t )va_arg(*ap, intmax_t );
	else if (t->elen == off)
		ret = va_arg(*ap, int);
	if (ret < 0)
		t->signe = '-';
	else if (ft_strchr(t->flag, '+'))
		t->signe = '+';
	return (ret);
}

uintmax_t get_unsigned_ent(va_list *ap, t_param *t)
{
	uintmax_t ret;

	if (t->elen == hh)
		ret = (unsigned int)va_arg(*ap, unsigned int);
	else if (t->elen == h)
		ret = (unsigned short int)va_arg(*ap, unsigned int);
	else if (t->elen == l)
		ret = (unsigned long int)va_arg(*ap, unsigned long int);
	else if (t->elen == ll)
		ret = (unsigned long long int)va_arg(*ap, unsigned long long int);
	else if (t->elen == j)
		ret = (uintmax_t )va_arg(*ap, uintmax_t);
	else if (t->elen == z)
		ret = (size_t)va_arg(*ap, size_t);
	else if (t->elen == off)
		ret = va_arg(*ap, unsigned int);
	return (ret);
}
char	*ft_strmap_i(char const *s, int (*f)(int))
{
	char	*new;
	int		i;

	i = 0;
	new = ft_strnew(ft_strlen(s));
	if (new == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		new[i] = f(s[i]);
		i++;
	}
	return (new);
}



int	get_value(t_param *param, va_list *ap)
{

	//printf("flag = %s \nspec = %c length = %i \nprecision = %i\nlargeur = %i\n",param->flag, param->spec  , param->elen , param->precision ,param->width  );




	if (param->spec == 'd' || param->spec == 'i')
	{
		param->value = ft_itoa(get_signed_ent(ap, param));
	}
	else if (param->spec == 'o')
	{
		param->value = ft_itoa_base_unintmax(get_unsigned_ent(ap, param), 8);
	}
	else if (param->spec == 'u')
	{
		param->value = ft_itoa_base_unintmax(get_unsigned_ent(ap, param), 10);
	}
	else if (param->spec == 'x')
	{
		param->value = ft_strmap_i(ft_itoa_base_unintmax(get_unsigned_ent(ap, param), 16), ft_tolower);
	}
	else if (param->spec == 'X')
	{
		param->value = ft_itoa_base_unintmax(get_unsigned_ent(ap, param), 16);
	}
	return (0);
}
