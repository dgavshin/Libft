/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:24:32 by acyrenna          #+#    #+#             */
/*   Updated: 2019/09/16 13:24:36 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_strlast(const char *str)
{
	const char	*tmp;

	tmp = str;
	if (tmp)
	{
		while (*(tmp + 1))
			tmp++;
		return (*tmp);
	}
	return (0);
}
