/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prefix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 17:24:57 by ptruffau          #+#    #+#             */
/*   Updated: 2018/10/04 17:24:58 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*get_prefix(t_param *p, char *tmp_val)
{
	char *ret;
	char *tmp;

	ret = NULL;
	tmp = NULL;
	p->var_len = ft_strlen(tmp_val);
	if (p->precision != -1 && p->precision > p->var_len 
	&& (TEST_SPEC_NBR(p->spec) || p->spec == '%'))
		ret = my_strjoin(ft_strnew_nchar('0', p->precision - p->var_len), ret);
	p->var_len = p->var_len + ft_strlen(ret);
	if (TEST_FLAG(p->flag, '#') || p->spec == 'p')
		tmp = get_ox(p, tmp_val);
	if (TEST_FLAG(p->flag, '0') && !TEST_FLAG(p->flag, '-') 
	&& (((TEST_SPEC_NBR(p->spec) || TEST_SPEC_WEIRD(p->spec))
	&& p->precision == -1) || TEST_SPEC_CHAR(p->spec)) 
	&& p->width > p->var_len)
		ret = my_strjoin(ft_strnew_nchar('0', p->width - p-> var_len -
		(p->signe != '?' ? 1 : 0) - TEST_FLAG(p->flag, ' ')), ret);
	if (TEST_FLAG(p->flag, '#') || p->spec == 'p')
		ret = my_strjoin(tmp, ret);
	if (p->signe != '?')
		ret = my_strjoin(ft_char_to_str(p->signe), ret);
	p->var_len = p->var_len + ft_strlen(ret);
	return (ret);
}

char		*get_value(t_param *p, va_list *ap)
{
	char *prefix;
	char *s;
	char *tmp_val;

	if (!(tmp_val = parse_spec(p, ap)))
		return (ft_strdup("(null)"));
	prefix = get_prefix(p, tmp_val);
	if (p->precision < p->var_len && p->precision != -1 && TEST_STR(p->spec)
	&& !(tmp_val = ft_strndup_fr(tmp_val, p->precision)))
		tmp_val = ft_strdup("");
	if ((TEST_SPEC_NBR(p->spec) || p->spec == 'p') && 
	p->precision == 0 && ft_atoi(tmp_val) == 0)
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
	return (my_strjoin(prefix, tmp_val));
}
