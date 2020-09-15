/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:16:57 by acyrenna          #+#    #+#             */
/*   Updated: 2019/09/16 13:19:18 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_c;
	const unsigned char	*s2_c;

	s1_c = (unsigned char *)s1;
	s2_c = (unsigned char *)s2;
	if (!n || s1 == s2)
		return (0);
	n = n - 1;
	while (*s1_c == *s2_c && n--)
	{
		s1_c++;
		s2_c++;
	}
	if (*s1_c == *s2_c)
		return (0);
	return (*s1_c - *s2_c);
}
