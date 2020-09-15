/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 12:45:42 by acyrenna          #+#    #+#             */
/*   Updated: 2019/09/17 12:46:57 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t size)
{
	size_t	i;
	size_t	d_size;
	size_t	s_size;
	size_t	j;

	i = 0;
	d_size = ft_strlen(dst);
	s_size = ft_strlen((char *)src);
	i = d_size;
	j = 0;
	if (size == 0)
		return (s_size + size);
	while (i < size - 1 && src[j] != '\0')
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	if (d_size + s_size < size + s_size)
		return (d_size + s_size);
	return (size + s_size);
}
