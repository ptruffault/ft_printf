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

	if (TEST_2OPTS(p->length, 'h'))
		ret = get_shh(ap);
	else if (TEST_FLAG(p->length, 'h'))
		ret = get_sh(ap);
	else if (TEST_FLAG(p->length, 'l'))
		ret = get_sl(ap);
	else if (TEST_2OPTS(p->length, 'l'))
		ret = get_sll(ap);
	else if (TEST_FLAG(p->length, 'j'))
		ret = get_sj(ap);
	else if (TEST_FLAG(p->length, 'z'))
		ret = get_sz(ap);
	else
		ret = va_arg(*ap, int);
	if (ret < 0)
	{
		ret = -ret;
		p->signe = '-';
	}
	else if (TEST_FLAG(p->flag, '+'))
		p->signe = '+';
	return (ret);
}

static uintmax_t	get_uent(va_list *ap, t_param *p)
{
	uintmax_t ret;

	if (TEST_2OPTS(p->length, 'h'))
		return ((unsigned int)va_arg(*ap, unsigned int));
	else if (TEST_FLAG(p->length, 'h') && p->spec != 'U')
		return ((unsigned short int)va_arg(*ap, unsigned int));
	else if (TEST_FLAG(p->length, 'l') || p->spec == 'O' || p->spec == 'U')
		return ((unsigned long int)va_arg(*ap, unsigned long int));
	else if (TEST_2OPTS(p->length, 'l'))
		return ((unsigned long long int)va_arg(*ap, unsigned long long int));
	else if (TEST_FLAG(p->length, 'j'))
		return ((uintmax_t)va_arg(*ap, uintmax_t));
	else if (TEST_FLAG(p->length, 'z'))
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
	if (p->spec == 'S' || (p->spec == 's' && TEST_FLAG(p->length, 'l')))
		return (ft_wstr(va_arg(*ap, int *), p->precision));
	if (p->spec == 's')
		return (ft_strdup(va_arg(*ap, char *)));
	if (p->spec == 'C' || (p->spec == 'c' && TEST_FLAG(p->length, 'l')))
		return (ft_wchar(va_arg(*ap, wchar_t)));
	if (p->spec == 'c' || (p->spec == 'C' && TEST_FLAG(p->length, 'h')))
		return (ft_char_to_str(va_arg(*ap, int)));
	if (p->spec == '%')
		return (ft_char_to_str('%'));
	return (NULL);
}

static char 		*get_prefix(t_param *p, char *tmp_val)
{
	char *ret;
	char *tmp;

	ret = NULL;;
	tmp = NULL;
	p->var_len = (ft_strlen(tmp_val) == 0 ? 1 : ft_strlen(tmp_val));
	if (p->precision != -1 && p->precision > p->var_len && (TEST_SPEC_NBR(p->spec)|| p->spec == '%'))
		ret = my_strjoin(ft_strnew_nchar('0', p->precision - p->var_len), ret);
	p->var_len = p->var_len + ft_strlen(ret);
	if (TEST_FLAG(p->flag, '#') || p->spec == 'p')
		tmp = get_ox(p, tmp_val);
	if (TEST_FLAG(p->flag, '0') && !TEST_FLAG(p->flag, '-') && ((TEST_SPEC_NBR(p->spec) && p->precision == -1) || TEST_SPEC_CHAR(p->spec)) && p->width > p->var_len)
		ret = my_strjoin(ft_strnew_nchar('0', p->width - p-> var_len - (p->signe != '?' ? 1 : 0)), ret);
	if (TEST_FLAG(p->flag, '#') || p->spec == 'p')
		ret = my_strjoin(tmp, ret);
	if (p->signe != '?')
		ret = my_strjoin(ft_char_to_str(p->signe), ret);
	p->var_len = p->var_len + ft_strlen(ret);
	return (ret);
}


char				*get_value(t_param *p, va_list *ap)
{
	char *prefix;
	char *s;
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
	if (*tmp_val == '-')
	{
		s = ft_strdup(&tmp_val[1]);
		ft_strdel(&tmp_val);
		tmp_val = s;
	}
	p->var_len = ft_strlen(tmp_val) + ft_strlen(prefix);
	return (my_strjoin(prefix, tmp_val));
}
