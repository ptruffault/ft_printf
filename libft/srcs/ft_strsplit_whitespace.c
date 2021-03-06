/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_whitespace.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 15:42:44 by ptruffau          #+#    #+#             */
/*   Updated: 2018/06/08 15:52:02 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_nw(char *s)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (IS_SPACE(s[i]))
		i++;
	while (s[i])
	{
		if (IS_SPACE(s[i]) && !(IS_SPACE(s[i - 1])))
			n++;
		i++;
	}
	if (!(IS_SPACE(s[i - 1])) && !s[i])
		n++;
	return (n);
}

char		**ft_strsplit_whitespace(char *str)
{
	int		i;
	int		k;
	char	**t;

	i = 0;
	k = 0;
	t = NULL;
	if (!(t = (char **)malloc(sizeof(char *) * ft_nw(str) + 1)))
	{
		error("allocation failed", "ft_strsplit_whitespace");
		return (NULL);
	}
	while (str[i] != '\0')
	{
		while (IS_SPACE(str[i]))
			i++;
		if (str[i] != '\0')
		{
			t[k] = ft_get_next_word(&str[i]);
			i = i + ft_strlen(t[k++]);
		}
	}
	t[k] = NULL;
	return (t);
}
