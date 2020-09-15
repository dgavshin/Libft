/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:26:12 by acyrenna          #+#    #+#             */
/*   Updated: 2019/09/16 13:26:27 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*tmp;
	const char	*last;

	tmp = s;
	last = NULL;
	while (*tmp)
	{
		if (ft_chrcmp(*tmp, c))
			last = tmp;
		tmp++;
	}
	if (*tmp == c)
		return ((char *)tmp);
	return ((char *)last);
}
