/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:18:29 by acyrenna          #+#    #+#             */
/*   Updated: 2019/09/16 16:06:17 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*dst_c;
	const unsigned char	*src_c;

	dst_c = (unsigned char *)dst;
	src_c = (unsigned char *)src;
	if (!len || src == dst)
		return (dst);
	i = 0;
	if (src_c < dst_c)
		while (++i <= len)
			dst_c[len - i] = src_c[len - i];
	else
		while (len-- > 0)
			*(dst_c++) = *(src_c++);
	return (dst);
}
