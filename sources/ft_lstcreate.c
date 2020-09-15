/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcreate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:14:41 by acyrenna          #+#    #+#             */
/*   Updated: 2020/04/30 12:03:57 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstcreate(t_list *list, void const *content, size_t content_size)
{
	t_list	*new_list;

	new_list = ft_lstnew(content, content_size);
	if (new_list)
	{
		new_list->next = list;
		if (list)
			list->prev = new_list;
		return (new_list);
	}
	return (NULL);
}
