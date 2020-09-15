/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:22:41 by acyrenna          #+#    #+#             */
/*   Updated: 2019/09/16 13:22:57 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*mem;

	if (!(ptr))
	{
		mem = malloc(size);
		return (mem);
	}
	if (ptr && size)
	{
		mem = malloc(size);
		ft_memcpy(mem, ptr, size);
		free(ptr);
		return (mem);
	}
	free(ptr);
	return (NULL);
}
