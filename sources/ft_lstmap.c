/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:15:14 by acyrenna          #+#    #+#             */
/*   Updated: 2019/09/16 13:42:32 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*first;
	t_list	*list;
	t_list	*tmp;

	tmp = f(lst);
	if (!f || !lst || !(list = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	first = list;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		if (!(list->next = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		lst = lst->next;
		list = list->next;
	}
	return (first);
}
