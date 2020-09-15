/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:25:37 by acyrenna          #+#    #+#             */
/*   Updated: 2019/09/16 16:10:55 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strnlen(const char *str, size_t maxlen)
{
	size_t		len;

	if (maxlen == 0 || !str)
		return (0);
	len = 0;
	while (*str++ && len <= maxlen)
		len++;
	return (maxlen >= len ? len : maxlen);
}
