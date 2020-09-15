/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:25:42 by acyrenna          #+#    #+#             */
/*   Updated: 2019/09/16 13:37:42 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t		same;
	size_t		tmp_n;
	const char	*str_tmp;
	const char	*find_tmp;

	if (!*to_find || to_find == str)
		return ((char *)str);
	while (*str && n--)
	{
		same = 0;
		str_tmp = str;
		find_tmp = to_find;
		tmp_n = ft_min(n, ft_strlen(to_find));
		while (*find_tmp == *str_tmp && *(str_tmp++)
				&& *(find_tmp++) && tmp_n + 1)
		{
			tmp_n--;
			same++;
		}
		if (same >= ft_strlen(to_find))
			return ((char *)str);
		str++;
	}
	return (NULL);
}
