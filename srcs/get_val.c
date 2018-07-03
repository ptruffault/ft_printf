#include "../includes/ft_printf.h"




char get_shh(va_list *ap)
{
	return(va_arg(*ap, int));
}

short int get_sh(va_list *ap)
{
	return ((signed short int)va_arg(*ap, signed int));
}

long int get_sl(va_list *ap)
{
	return ((signed long int)va_arg(*ap, signed long int));
}

long long int get_sll(va_list *ap)
{
	return ((signed long long int)va_arg(*ap, signed long long int));
}

intmax_t get_sj(va_list *ap)
{
	return ((intmax_t)va_arg(*ap, intmax_t));
}

size_t	get_sz(va_list *ap)
{
	return ((size_t)va_arg(*ap, size_t));
}


static intmax_t		get_ent(va_list *ap, t_param *p)
{
	intmax_t ret;


	if (p->elen == hh)
		ret = get_shh(ap);
	else if (p->elen == h)
		ret = get_sh(ap);
	else if (p->elen == l)
		ret = get_sl(ap);
	else if (p->elen == ll)
		ret = get_sll(ap);
	else if (p->elen == j)
		ret = get_sj(ap);
	else if (p->elen == z)
		ret = get_sz(ap);
	else
		ret = va_arg(*ap, int);
	if (ret < 0)
	{
		ret = -ret;
		p->signe = '-';
	}
	else if (TEST_FLAG('+'))
		p->signe = '+';
	return (ret);
}

static uintmax_t	get_uent(va_list *ap, t_param *p)
{
	uintmax_t ret;

	if (p->elen == hh)
		return ((unsigned int)va_arg(*ap, unsigned int));
	else if (p->elen == h)
		return ((unsigned short int)va_arg(*ap, unsigned int));
	else if (p->elen == l || p->spec == 'O' || p->spec == 'U')
		return ((unsigned long int)va_arg(*ap, unsigned long int));
	else if (p->elen == ll)
		return ((unsigned long long int)va_arg(*ap, unsigned long long int));
	else if (p->elen == j)
		return ((uintmax_t)va_arg(*ap, uintmax_t));
	else if (p->elen == z)
		return ((size_t)va_arg(*ap, size_t));
	else
		return (va_arg(*ap, unsigned int));
	return (ret);
}

static char			*parse_spec(t_param *p, va_list *ap)
{
	if (p->spec == 'd' || p->spec == 'i' || p->spec == 'D')
		return (ft_itoa_base(get_ent(ap, p), 10));
	if (p->spec == 'o' || p->spec == 'O')
		return (ft_itoa_base_u(get_uent(ap, p), 8));
	if (p->spec == 'u' || p->spec == 'U')
		return (ft_itoa_base_u(get_uent(ap, p), 10));
	if (p->spec == 'x')
		return (ft_itoa_base_u(get_uent(ap, p), 16));
	if (p->spec == 'X')
		return (ft_strmap_i(ft_itoa_base_u(get_uent(ap, p), 16), ft_toupper));
	if (p->spec == 'p')
		return (ft_itoa_base_u(va_arg(*ap, uintmax_t), 16));
	if (p->spec == 'S' || (p->spec == 's' && p->elen == l))
		return (ft_wstr(va_arg(*ap, int *), p->precision));
	if (p->spec == 's')
		return (ft_strdup(va_arg(*ap, char *)));
	if (p->spec == 'C' || (p->spec == 'c' && p->elen == l))
		return (ft_wchar(va_arg(*ap, wchar_t)));
	if (p->spec == 'c' || (p->spec == 'C' && p->elen == h))
		return (ft_char_to_str(va_arg(*ap, int)));
	if (p->spec == '%')
		return (ft_char_to_str('%'));
	return (NULL);
}
/*
static char 		*get_prefix(t_param *p, char *tmp_val)
{
	char	*ret;

	ret = NULL;

	if (p->width > p->var_len && !TEST_FLAG('-'))
		ret = my_strjoin(ret, ft_strnew_nchar(' ', p->width - p->precision - (p->signe != '?' ? -1 : 0)));
	if (p->signe != '?')
		ret = ft_stradd_char(ret, p->signe);
	else if (TEST_FLAG(' ') && (p->spec == 'i' || p->spec == 'd'))
		ret = ft_stradd_char(ret, ' ');
	if (TEST_FLAG('#') || p->spec == 'p')
		ret = my_strjoin(ret, get_ox(p, tmp_val));
	if (p->precision > p->var_len && TEST_SPEC_NBR(p->spec))
		ret = my_strjoin(ret, ft_strnew_nchar('0', p->precision - p->var_len));
	p->var_len = ft_strlen(ret) + ft_strlen(tmp_val);
	if ((p->width > p->var_len && TEST_FLAG('0') && !TEST_FLAG('-')))
		ret = my_strjoin(ret, ft_strnew_nchar('0', p->width - p->var_len + (p->signe != '?' ? -1 : 0)));
	p->var_len = ft_strlen(ret) + ft_strlen(tmp_val);
	return (ret);
}
*/
static char 		*get_prefix(t_param *p, char *tmp_val)
{
	char *ret;
	char *tmp;

	ret = NULL;
	tmp = NULL;
	p->var_len = (ft_strlen(tmp_val) == 0 ? 1 : ft_strlen(tmp_val));
	if (p->precision != -1 && p->precision > p->var_len && TEST_SPEC_NBR(p->spec))
		ret = my_strjoin(ft_strnew_nchar('0', p->precision - p->var_len), ret);
	p->var_len = p->var_len + ft_strlen(ret);
	if (TEST_FLAG('#') || p->spec == 'p')
		tmp = get_ox(p, tmp_val);
	if (TEST_FLAG('0') && !TEST_FLAG('-') && ((TEST_SPEC_NBR(p->spec) && p->precision == -1) || TEST_SPEC_CHAR(p->spec)) && p->width > p->var_len)
		ret = my_strjoin(ft_strnew_nchar('0', p->width - p-> var_len - (p->signe != '?' ? 1 : 0)), ret);
	if (TEST_FLAG('#') || p->spec == 'p')
		ret = my_strjoin(tmp, ret);
	if (p->signe != '?')
		ret = my_strjoin(ft_char_to_str(p->signe), ret);

	p->var_len = p->var_len + ft_strlen(ret);
	return (ret);
}


char				*get_value(t_param *p, va_list *ap)
{
	char *prefix;
	char *tmp_val;

	if (!(tmp_val = parse_spec(p, ap)))
		return (ft_strdup("(null)")); 
	prefix = get_prefix(p, tmp_val);
	if (p->precision < p->var_len && p->precision != -1 && TEST_STR(p->spec))
		tmp_val = ft_strndup_fr(tmp_val, p->precision);
	if ((TEST_SPEC_NBR(p->spec) || p->spec == 'p') && p->precision == 0 && ft_atoi(tmp_val) == 0)
	{
		ft_strdel(&tmp_val);
		tmp_val = ft_strnew(0);
	}
	p->var_len = ft_strlen(tmp_val) + ft_strlen(prefix);
	return (my_strjoin(prefix, tmp_val));
}
