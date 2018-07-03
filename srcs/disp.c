/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 15:36:45 by ptruffau          #+#    #+#             */
/*   Updated: 2018/06/21 15:36:47 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print(char *format, t_param *p)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			if (p->width > p->var_len && !TEST_FLAG('-'))
			{
				ft_putnchar(' ', p->width - p->var_len);
				ret = ret + p->width - p->var_len;
			}
			else if (TEST_FLAG(' ') && TEST_SIGN(p->spec) && p->signe == '?')
			{
				ft_putchar(' ');
				ret ++;
			}

			if (TEST_CHAR(p->spec) && p->value[p->var_len -1] == 0)
			{
				ret++;
				ft_putchar('\0');
			}
			else
				ft_putstr(p->value);
			ret = ret + ft_strlen(p->value) - 1;
			if (p->width > p->var_len && TEST_FLAG('-'))
			{
				ft_putnchar(' ', p->width - p->var_len);
				ret = ret + p->width - p->var_len;
			}
			i = i + p->opts_len;
			p = p->next;
		}
		else
			ft_putchar(format[i++]);
		ret++;
	}
	return (ret);
}
