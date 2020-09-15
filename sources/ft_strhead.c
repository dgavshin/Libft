/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strhead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:23:54 by acyrenna          #+#    #+#             */
/*   Updated: 2020/09/14 00:24:05 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strhead(void *dst, const void *src, size_t tail)
{
	char		*dst_c;
	const char	*src_c;
	size_t		len;
	size_t		last;
	size_t		i;

	i = 0;
	dst_c = dst;
	src_c = src;
	len = ft_strlen(src);
	if (src_c && dst_c && tail <= len)
	{
		last = tail;
		while (src_c[i] && tail)
		{
			dst_c[i] = src_c[i];
			tail--;
			i++;
		}
		dst_c[last] = '\0';
		return (dst);
	}
	return (0);
}
