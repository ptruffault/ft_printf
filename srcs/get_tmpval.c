/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 15:36:45 by ptruffau          #+#    #+#             */
/*   Updated: 2018/06/21 15:36:47 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char			get_char(t_param *p, va_list *ap, int sgd)
{
	int c;
	int vmin;
	int vmax;

	vmin = (sgd == 1 ? -128 : 0);
	vmax = (sgd == 1 ? 127 : 255);
	c = va_arg(*ap, int);
	c = (c > vmax ? vmin : c);
	c = (c < vmin ? vmax : c);
	return ((char)c);
}

static intmax_t		get_ent(va_list *ap, t_param *p)
{
	intmax_t ret;

	if (TEST_FLAG(p->length, 'j'))
		ret = (intmax_t)va_arg(*ap, intmax_t);
	else if (TEST_FLAG(p->length, 'z'))
		ret = (size_t)va_arg(*ap, size_t);
	else if (TEST_2OPTS(p->length, 'l'))
		ret = (signed long long int)va_arg(*ap, signed long long int);
	else if (TEST_FLAG(p->length, 'l') || p->spec == 'D')
		ret = (signed long int)va_arg(*ap, signed long int);
	else if (TEST_FLAG(p->length, 'h'))
		ret = (signed short int)va_arg(*ap, signed int);
	else if (TEST_2OPTS(p->length, 'h'))
		ret = (signed char)get_char(p, ap, 1);
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

	if (TEST_FLAG(p->length, 'z'))
		return ((size_t)va_arg(*ap, size_t));
	else if (TEST_FLAG(p->length, 'j'))
		return ((uintmax_t)va_arg(*ap, uintmax_t));
	else if (TEST_2OPTS(p->length, 'h'))
		return (get_char(p, ap, 0));
	else if (TEST_FLAG(p->length, 'h') && p->spec != 'U')
		return ((unsigned short int)va_arg(*ap, unsigned int));
	else if (TEST_2OPTS(p->length, 'l'))
		return ((unsigned long long int)va_arg(*ap, unsigned long long int));
	else if (TEST_FLAG(p->length, 'l') || p->spec == 'O' || p->spec == 'U')
		return ((unsigned long int)va_arg(*ap, unsigned long int));
	else
		return (va_arg(*ap, unsigned int));
	return (ret);
}

static char			*parse_spec_again(t_param *p, va_list *ap)
{
	char *ret;

	if (p->spec == 'C' || (p->spec == 'c' && TEST_FLAG(p->length, 'l')))
	{
		ret = ft_wchar(va_arg(*ap, wchar_t));
		p->exep = (*ret == 0 ? 1 : 0);
		return (ret);
	}
	if (p->spec == 'c' || (p->spec == 'C' && TEST_FLAG(p->length, 'h')))
	{
		ret = ft_char_to_str(get_char(p, ap, 1));
		p->exep = (*ret == 0 ? 1 : 0);
		return (ret);
	}
	if (p->spec == '%')
		return (ft_char_to_str('%'));
	return (NULL);
}

char				*parse_spec(t_param *p, va_list *ap)
{
	int *ret;

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
	{
		if (!(ret = va_arg(*ap, int *)))
			return (NULL);
		return (ft_wstr(ret, p->precision));
	}
	if (p->spec == 's')
		return (ft_strdup(va_arg(*ap, char *)));
	return (parse_spec_again(p, ap));
}
