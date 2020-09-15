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

#define LOWER_BOUND_LIM 19
#define UPPER_BOUND_LIM 20
#define LOWER_BOUND 922337203685477580
#define UPPER_BOUND 1844674407370955161
#define OK 1
#define ERROR_LOW 0
#define ERROR_UP -1

static int		check_upper_bound(const char *str)
{
	signed long int	n_sli;
	const char		*tmp;
	size_t			lim;
	size_t			len;

	tmp = str;
	n_sli = 0;
	len = ft_strndigc(tmp, UPPER_BOUND_LIM + 1);
	lim = UPPER_BOUND_LIM - 1;
	if (len < UPPER_BOUND_LIM)
		return (OK);
	if (len == UPPER_BOUND_LIM)
	{
		while (ft_isdigit(*tmp) && lim--)
			n_sli = n_sli * 10 + (*(tmp++) - '0');
		if (n_sli < UPPER_BOUND || (n_sli == UPPER_BOUND &&
					ft_isdigit(tmp[len - 1]) && tmp[len - 1] < '7'))
			return (OK);
	}
	return (ERROR_UP);
}

static int		check_lower_bound(const char *str)
{
	signed long int	n_sli;
	const char		*tmp;
	size_t			lim;
	size_t			len;

	tmp = str;
	n_sli = 0;
	len = ft_strndigc(tmp, LOWER_BOUND_LIM + 1);
	lim = LOWER_BOUND_LIM - 1;
	if (len < LOWER_BOUND_LIM)
		return (OK);
	if (len == LOWER_BOUND_LIM)
	{
		while (ft_isdigit(*tmp) && lim--)
			n_sli = n_sli * 10 + (*(tmp++) - '0');
		if (n_sli < LOWER_BOUND || (n_sli == LOWER_BOUND &&
					ft_isdigit(tmp[len - 1]) && tmp[len - 1] < '9'))
			return (OK);
	}
	return (ERROR_LOW);
}

static int		check_bounds(const char *str, int sign)
{
	const char	*tmp;

	tmp = str;
	return ((sign == -1) ? check_lower_bound(tmp) : check_upper_bound(tmp));
}

int				ft_atoi(const char *str)
{
	const char	*tmp;
	int			sign;
	int			nbr;
	int			error;

	nbr = 0;
	sign = 1;
	tmp = str;
	while (*tmp == ' ' || *tmp == '\b' || *tmp == '\n' ||
	*tmp == '\t' || *tmp == '\v' || *tmp == '\f' || *tmp == '\r')
		tmp++;
	if (*tmp == '-' || *tmp == '+')
		sign = (*(tmp++) == '-' ? -1 : 1);
	while (*tmp == '0')
		tmp++;
	error = check_bounds(tmp, sign);
	if (error != OK)
		return (error);
	while (ft_isdigit(*tmp))
		nbr = nbr * 10 + (*(tmp++) - '0');
	return (nbr * sign);
}
