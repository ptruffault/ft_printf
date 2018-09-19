/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_word.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 14:10:22 by ptruffau          #+#    #+#             */
/*   Updated: 2018/06/21 14:10:26 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int		ft_is_quote(char *str)
{
	char *ptr;

	if (*str == '"' || *str == '\'')
	{
		if ((ptr = ft_strchr(str + 1, *str)))
			return (1);
		return (-1);
	}
	return (0);
}

static int		word_len(char *str)
{
	int i;

	i = 0;
	if (ft_is_quote(str) < 1)
	{
		while (!(IS_SPACE(str[i])) && str[i] != '\0')
			i++;
		return (i);
	}
	else
		return (ft_strchr(str + 1, *str) - (str + 1));
	return (-1);
}

static char		**init_tab(char *s)
{
	int		i;
	int		n;
	char	*ptr;

	i = 0;
	n = 0;
	while (s[i] != '\0')
	{
		if (!(IS_SPACE(s[i])))
		{
			if ((s[i] == '"' || s[i] == '\'')
			&& (ptr = ft_strchr(&s[i + 1], s[i])))
				i = i + (ptr - &s[i]);
			else
			{
				while (!(IS_SPACE(s[i])) && s[i] != '\0')
					i++;
			}
			n++;
		}
		if (s[i] != '\0')
			i++;
	}
	return ((char **)malloc(sizeof(char *) * (n + 1)));
}

static char		*get_next_word(char *str)
{
	char	*word;
	int		len;
	int		r;

	len = word_len(str);
	if (!(word = ft_strnew(len)))
		return (NULL);
	r = ft_is_quote(str);
	if (r == 1)
		word = ft_strncpy(word, str + 1, len);
	else if (r == 0)
		word = ft_strncpy(word, str, len);
	else if (*(str + 1) != '\0')
		word = ft_strncpy(word, str + 1, len - 1);
	return (word);
}

char			**ft_strsplit_word(char *str)
{
	char	**tab;
	int		k;
	int		i;
	int		r;

	if (!(tab = init_tab(str)))
		return (NULL);
	k = 0;
	i = 0;
	while (str[i])
	{
		if (!(IS_SPACE(str[i])))
		{
			if (!(tab[k++] = get_next_word(&str[i])))
				return (tab);
			r = ft_is_quote(&str[i]);
			i = i + word_len(&str[i]) + (r == 1 ? 2 : 0)
			+ (r == -1 ? 1 : 0);
		}
		else
			i++;
	}
	tab[k] = NULL;
	return (tab);
}
