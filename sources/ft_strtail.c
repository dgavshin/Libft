/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtail.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:26:59 by acyrenna          #+#    #+#             */
/*   Updated: 2020/09/14 00:25:32 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtail(void *dst, const void *src, size_t tail)
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
		while (src_c[len - tail] && tail)
		{
			dst_c[i] = src_c[len - tail];
			tail--;
			i++;
		}
		dst_c[last] = '\0';
		return (dst);
	}
	return (0);
}
