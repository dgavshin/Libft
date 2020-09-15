/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:24:53 by acyrenna          #+#    #+#             */
/*   Updated: 2019/09/16 13:24:54 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char *s1_u;
	const unsigned char *s2_u;

	s1_u = (unsigned char*)s1;
	s2_u = (unsigned char*)s2;
	if (n <= 0)
		return (0);
	n = n - 1;
	while (*s1_u == *s2_u && n && *s1_u && *s1_u)
	{
		s1_u++;
		s2_u++;
		n--;
	}
	return (*s1_u - *s2_u);
}
