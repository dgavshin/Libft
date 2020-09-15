/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:23:05 by acyrenna          #+#    #+#             */
/*   Updated: 2019/09/16 13:36:51 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char	*tmp;

	tmp = s;
	while (*tmp)
	{
		if (ft_chrcmp(*tmp, c))
			return ((char*)tmp);
		tmp++;
	}
	if (*tmp == c)
		return ((char*)tmp);
	return (NULL);
}
