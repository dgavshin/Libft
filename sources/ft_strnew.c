/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:25:29 by acyrenna          #+#    #+#             */
/*   Updated: 2019/09/16 13:25:36 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	if (size + 1 > size)
	{
		if ((str = (char*)malloc(sizeof(char) * (size + 1))))
			return ((char*)ft_memset(str, '\0', size + 1));
	}
	return (NULL);
}
