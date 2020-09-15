/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 09:41:36 by acyrenna          #+#    #+#             */
/*   Updated: 2019/09/14 09:41:39 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		*arr;
	int		i;

	i = 0;
	arr = (int*)malloc(sizeof(*arr) * (max - min));
	if (min >= max)
		return (0);
	if (!arr)
		return (0);
	while (min < max)
	{
		arr[i] = min++;
		i++;
	}
	return (arr);
}
