/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:24:51 by acyrenna          #+#    #+#             */
/*   Updated: 2019/09/16 16:17:41 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	size_t d_len;
	size_t i;

	d_len = ft_strlen(s1);
	i = 0;
	while (s2[i] && n)
	{
		s1[d_len + i] = s2[i];
		i++;
		n--;
	}
	s1[d_len + i] = '\0';
	return (s1);
}
