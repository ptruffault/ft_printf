#include "../includes/ft_printf.h"

static intmax_t get_signed_ent(va_list *ap, t_param *p)
{
	intmax_t ret;

	if (p->elen == hh)
		ret = va_arg(*ap, int);
	else if (p->elen == h)
		ret = (signed short int)va_arg(*ap, signed int);
	else if (p->elen == l)
		ret = (signed long int)va_arg(*ap, signed long int);
	else if (p->elen == ll)
		ret = (signed long long int)va_arg(*ap, signed long long int);
	else if (p->elen == j)
		ret = (intmax_t )va_arg(*ap, intmax_t );
	else if (p->elen == off)
		ret = va_arg(*ap, int);
	if (ret < 0)
	{
		ret = -ret;
		p->signe = '-';
	}
	else if (p->flag && (ft_strchr(p->flag, '+') || ft_strchr(p->flag, ' ')))
		p->signe = '+';
	return (ret);
}

static uintmax_t get_unsigned_ent(va_list *ap, t_param *p)
{
	uintmax_t ret;

	if (p->elen == hh)
		ret = (unsigned int)va_arg(*ap, unsigned int);
	else if (p->elen == h)
		ret = (unsigned short int)va_arg(*ap, unsigned int);
	else if (p->elen == l)
		ret = (unsigned long int)va_arg(*ap, unsigned long int);
	else if (p->elen == ll)
		ret = (unsigned long long int)va_arg(*ap, unsigned long long int);
	else if (p->elen == j)
		ret = (uintmax_t )va_arg(*ap, uintmax_t);
	else if (p->elen == z)
		ret = (size_t)va_arg(*ap, size_t);
	else if (p->elen == off)
		ret = va_arg(*ap, unsigned int);
	return (ret);
}

static char	*parse_spec(t_param *p, va_list *ap)
{
//printf("flag = %s \nspec = %c length = %i \nprecision = %i\nlargeur = %i\n",p->flag, p->spec  , p->elen , p->precision ,p->width  );
	if (p->spec == 'd' || p->spec == 'i')
		return(ft_itoa_base_intmax(get_signed_ent(ap, p), 10));
	else if (p->spec == 'o')
		return (ft_itoa_base_unintmax(get_unsigned_ent(ap, p), 8));
	else if (p->spec == 'u')
		return (ft_itoa_base_unintmax(get_unsigned_ent(ap, p), 10));
	else if (p->spec == 'x')
		return (ft_itoa_base_unintmax(get_unsigned_ent(ap, p), 16));
	else if (p->spec == 'X')
		return (ft_strmap_i(ft_itoa_base_unintmax(get_unsigned_ent(ap, p), 16), ft_toupper));
	return (NULL);
}

static char *get_prefix(t_param *p, char *tmp_val)
{
	char **tab;
	char *ret;
	int i;

	i = 0;
	if (!(tab = (char **)malloc(sizeof (char *) * 5)))
		return (NULL);
	p->var_len = ft_strlen(tmp_val);
	if (p->signe != '?')
		tab[i++] = char_to_str(p->signe);
	if (TEST_FLAG('#'))
		tab[i++] = get_dat_flag(p);
	if (p->precision > p->var_len)
		tab[i++] = ft_strnew_nchar('0', p->precision - p->var_len);
	if ((p->width > p->var_len && TEST_FLAG('0') && !TEST_FLAG('-'))) 
		tab[i++] = ft_strnew_nchar('0', p->width - p->var_len);
	tab[i] = NULL;
	ret = ft_arr_to_str(tab);
		p->var_len = ft_strlen(ret) + ft_strlen(tmp_val);
	ft_freenstrarr(tab, 5);
	return (ret);
}

char 	*get_dioux(t_param *p, va_list *ap)
{
	char *prefix;
	char *tmp_val;

	if (!(tmp_val = parse_spec(p, ap)))
		return (NULL);
	prefix = get_prefix(p, tmp_val);
	if (p->width > p->var_len && !TEST_FLAG('0') && !TEST_FLAG('-'))
		prefix = ft_strjoin_fr(ft_strnew_nchar(' ', p->width - p->var_len), prefix);
	else if (p->width > p->var_len && TEST_FLAG('-'))
		tmp_val = ft_strjoin_fr(tmp_val, ft_strnew_nchar(' ', p->width - p->var_len));
	return (my_strjoin(prefix, tmp_val));
}