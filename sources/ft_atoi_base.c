/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:01:59 by acyrenna          #+#    #+#             */
/*   Updated: 2019/09/16 16:00:47 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_atoi_base(const char *str, size_t base)
{
	int			nbr;

	if (base < 2 || base > 16)
		return (0);
	nbr = 0;
	while (*str == ' ' || *str == '\b' || *str == '\n' ||
	*str == '\t' || *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-')
		return (0);
	while (*str == '0')
		str++;
	while (ft_isdigit(*str))
		nbr = nbr * base + (*(str++) - '0');
	return (nbr);
}
