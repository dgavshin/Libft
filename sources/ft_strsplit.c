/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:26:29 by acyrenna          #+#    #+#             */
/*   Updated: 2020/09/14 00:29:08 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(const char *str, char c)
{
	int		len;

	len = 0;
	while (*str && *str != c)
	{
		len++;
		str++;
	}
	return (len);
}

int			word_count(const char *str, char c)
{
	int		count;

	count = 0;
	while (*str)
	{
		if (*str != c)
		{
			count++;
			while (*str != c)
			{
				if (!*str)
					return (count);
				str++;
			}
		}
		str++;
	}
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	int		j;
	int		i;
	char	**list;

	j = 0;
	i = 0;
	if (!s || (!(list = (char **)malloc(8 * (word_count(s, c) + 1)))))
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			if (!(list[j] = (char *)malloc(sizeof(char) * (get_len(s, c) + 1))))
				return (NULL);
			while (*s && *s != c)
				list[j][i++] = (char)*s++;
			list[j][i] = '\0';
			j++;
			i = 0;
		}
	}
	list[j] = NULL;
	return (list);
}
