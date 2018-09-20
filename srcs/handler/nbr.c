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

static intmax_t relatif(intmax_t ret, t_param *p)
{
	if (ret < 0)
	{
		ret = -ret;
		p->signe = '-';
	}
	else if (TEST_FLAG(p->flag, '+'))
		p->signe = '+';
	return (ret);
}


static char *get_ent(va_list *ap, t_param *p, int base)
{
	intmax_t ret;

	if (TEST_FLAG(p->length, 'j'))
		return (ft_itoa_base(relatif((intmax_t)va_arg(*ap, intmax_t), p), base));
	else if (TEST_2OPTS(p->length, 'l'))
		return (ft_itoa_base(relatif(va_arg(*ap, signed long long int), p), base));
	else if (TEST_FLAG(p->length, 'l'))
		return (ft_itoa_base(relatif(va_arg(*ap, signed long int), p), base));
	else if (TEST_FLAG(p->length, 'h'))
		return (ft_itoa_base(relatif(va_arg(*ap, signed int), p), base));
	else if (TEST_2OPTS(p->length, 'h'))
		return (ft_itoa_base(relatif((char)va_arg(*ap, int), p), base));
	else if (TEST_FLAG(p->length, 'z'))
		return (ft_itoa_base(relatif((size_t)va_arg(*ap, size_t), p), base));
	else
		return(ft_itoa_base(relatif((int)va_arg(*ap, int), p), base));
}

static char *get_uent(va_list *ap, t_param *p, int base)
{
	uintmax_t ret;

	if (TEST_2OPTS(p->length, 'h'))
		return (ft_itoa_base_u((unsigned int)va_arg(*ap, unsigned int), base));
	else if (TEST_FLAG(p->length, 'h') && p->spec != 'U')
		return (ft_itoa_base_u((unsigned short int)va_arg(*ap, unsigned int), base));
	else if (TEST_FLAG(p->length, 'l') || p->spec == 'O' || p->spec == 'U')
		return (ft_itoa_base_u((unsigned long int)va_arg(*ap, unsigned long int), base));
	else if (TEST_2OPTS(p->length, 'l'))
		return (ft_itoa_base_u((unsigned long long int)va_arg(*ap, unsigned long long int), base));
	else if (TEST_FLAG(p->length, 'j'))
		return (ft_itoa_base_u((uintmax_t)va_arg(*ap, uintmax_t), base));
	else if (TEST_FLAG(p->length, 'z'))
		return (ft_itoa_base_u((size_t)va_arg(*ap, size_t), base));
	return (ft_itoa_base(va_arg(*ap, unsigned int), base));
}

static char 		*parse_spec_again(t_param *p, va_list *ap)
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
		ret = ft_char_to_str(va_arg(*ap, int));
		p->exep = (*ret == 0 ? 1 : 0);
		return (ret);
	}
	if (p->spec == '%')
		return (ft_char_to_str('%'));
	return (NULL);

}



char			*parse_spec(t_param *p, va_list *ap)
{
	int *ret;

	if (p->spec == 'd' || p->spec == 'i' || p->spec == 'D')
		return (get_uent(ap, p, 10));
	if (p->spec == 'o' || p->spec == 'O')
		return (get_uent(ap, p, 8));
	if (p->spec == 'u' || p->spec == 'U')
		return (get_uent(ap, p, 10));
	if (p->spec == 'x')
		return (get_uent(ap, p, 16));
	if (p->spec == 'X')
		return (ft_strmap_i(get_uent(ap, p, 16), ft_toupper));
	if (p->spec == 'p')
		return (get_uent(ap, p, 16));
	if (p->spec == 'S' || (p->spec == 's' && TEST_FLAG(p->length, 'l')))
	{
		if (!(ret = va_arg(*ap, int *)))
			return (NULL);
		return (ft_wstr(ret, p->precision));
	}
	if (p->spec == 's')
		return (ft_strdup(va_arg(*ap, char *)));
	return(parse_spec_again(p, ap));
}