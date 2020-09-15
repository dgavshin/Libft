/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:23:29 by acyrenna          #+#    #+#             */
/*   Updated: 2019/09/16 16:11:53 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*tmp;

	tmp = (char *)ft_memalloc(ft_strlen(s1) + 3);
	if (tmp)
	{
		ft_strcpy(tmp, s1);
		return (tmp);
	}
	return (NULL);
}
