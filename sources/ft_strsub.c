/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:26:49 by acyrenna          #+#    #+#             */
/*   Updated: 2019/09/16 13:39:27 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*substr;
	size_t		i;

	i = 0;
	if (!s || !len)
		return (NULL);
	start = (start >= (unsigned int)ft_strlen(s) ? 0 : start);
	if (!(substr = (char*)malloc(len + 1)))
		return (NULL);
	while (len--)
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}
