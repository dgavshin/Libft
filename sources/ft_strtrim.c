/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:27:11 by acyrenna          #+#    #+#             */
/*   Updated: 2019/09/16 13:40:10 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isnotend(const char *str)
{
	while (*str)
		if (!(ft_isspace(*(str++))))
			return (1);
	return (0);
}

static int	isnotbegin(const char *start, int end)
{
	int i;

	i = 0;
	while (i <= end)
	{
		if (!(ft_isspace(start[i])))
			return (1);
		i++;
	}
	return (0);
}

static int	get_len(const char *s)
{
	const char	*tmp;
	size_t		len;
	size_t		i;

	i = 0;
	len = 0;
	tmp = s;
	while (tmp[i])
	{
		if (!(ft_isspace(tmp[i])) || (isnotbegin(s, i) && isnotend(tmp + i)))
			len++;
		i++;
	}
	return (len);
}

char		*ft_strtrim(char const *s)
{
	char	*trimmed;
	size_t	len;
	size_t	i;
	size_t	j;

	if (!s)
		return (0);
	len = get_len(s);
	i = 0;
	j = 0;
	if (!(trimmed = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s[i])
	{
		if (!(ft_isspace(s[i])) || (isnotbegin(s, i) && isnotend(s)))
			trimmed[j++] = s[i];
		i++;
	}
	trimmed[len] = '\0';
	return (trimmed);
}
