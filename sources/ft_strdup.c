/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:23:29 by acyrenna          #+#    #+#             */
/*   Updated: 2019/09/16 16:11:53 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*tmp;

	if (!(len = ft_strlen(s1)))
		return (NULL);
	if (!(tmp = (char *)ft_memalloc(len)))
		return (NULL);
	ft_memcpy((void *)tmp, (void *)s1, len);
	return (tmp);
}
