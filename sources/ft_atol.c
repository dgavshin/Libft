/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <acyrenna@school21.ru>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 17:56:34 by acyrenna          #+#    #+#             */
/*   Updated: 2020/09/15 17:56:35 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_sign(char c)
{
	return (c == '-' || c == '+');
}

void	check_errors(char *str, int *errno)
{
	int after_num;

	if (!errno)
		return ;
	after_num = 0;
	while (*str)
	{
		if (!ft_isdigit(*str) && (!is_sign(*str) ||
				(is_sign(*str) && after_num == 1)))
		{
			*errno = 1;
			return ;
		}
		else if (ft_isdigit(*str))
			after_num = 1;
		str++;
	}
	*errno = 0;
}

long	ft_atol(char *str, int *errno)
{
	long long	res;
	int			sign;

	if (!str || !*str)
		return (0);
	check_errors(str, errno);
	res = 0;
	sign = 1;
	while (*str && ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		sign = *(str++) == '-' ? -1 : 1;
	while (*str == '0')
		str++;
	while (ft_isdigit(*str))
		res = res * 10 + (*(str++) - '0');
	return (res * sign);
}
