/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:24:56 by acyrenna          #+#    #+#             */
/*   Updated: 2020/05/05 15:07:16 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*tmp;

	tmp = dst;
	while (*src && len)
	{
		*(tmp++) = *(src++);
		len--;
	}
	while (len > 0)
	{
		*(tmp++) = '\0';
		len--;
	}
	return (dst);
}
