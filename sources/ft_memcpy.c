/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:17:33 by acyrenna          #+#    #+#             */
/*   Updated: 2019/09/16 16:03:19 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cpy_long_blocks(unsigned long *dest_l, const
			unsigned long *src_l, size_t n)
{
	int	block;
	int	i;

	i = 0;
	block = n / sizeof(long);
	while (i++ < block)
		*(dest_l++) = *(src_l++);
	return (i - 1);
}

static void	cpy_char_blocks(unsigned char *dest_c, const
			unsigned char *src_c, size_t n)
{
	int	block;
	int	i;

	i = 0;
	block = n % sizeof(long);
	while (i++ < block)
		*(dest_c++) = *(src_c++);
}

void		*ft_memcpy(void *restrict dest, const void *restrict src, size_t n)
{
	unsigned long		*dest_l;
	unsigned char		*dest_c;
	const unsigned long	*src_l;
	const unsigned char	*src_c;
	int					offset;

	if (!n || src == dest)
		return (dest);
	dest_l = dest;
	src_l = src;
	offset = cpy_long_blocks(dest_l, src_l, n);
	dest_c = (unsigned char *)(dest_l + offset);
	src_c = (unsigned char *)(src_l + offset);
	cpy_char_blocks(dest_c, src_c, n);
	return (dest);
}
