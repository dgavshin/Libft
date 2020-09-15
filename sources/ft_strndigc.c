/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndigc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:25:02 by acyrenna          #+#    #+#             */
/*   Updated: 2019/09/16 13:25:11 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strndigc(const char *str, size_t max)
{
	int		len;

	len = 0;
	while (ft_isdigit(str[len]) && max)
	{
		len++;
		max--;
	}
	return (len);
}
