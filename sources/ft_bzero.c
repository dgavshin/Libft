/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:11:49 by acyrenna          #+#    #+#             */
/*   Updated: 2019/09/16 13:11:54 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	zero_long_blocks(unsigned long long *dest_l, size_t blocks)
{
	int	i;

	i = 0;
	while (i++ < blocks)
		*(dest_l++) = 0;
	return (i - 1);
}

static void	zero_char_blocks(unsigned char *dest_c, size_t blocks)
{
	int	i;

	i = 0;
	while (i++ < blocks)
		*(dest_c++) = 0;
}

void		ft_bzero(void *restrict dest, size_t n)
{
	unsigned long long	*dest_l;
	unsigned char		*dest_c;
	int					offset;

	if (!n)
		return ;
	dest_l = dest;
	offset = zero_long_blocks(dest_l, n / sizeof(unsigned long long));
	dest_c = (unsigned char *)(dest_l + offset);
	zero_char_blocks(dest_c, n % sizeof(unsigned long long));
}
