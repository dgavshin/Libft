/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 15:18:41 by acyrenna          #+#    #+#             */
/*   Updated: 2021/02/13 15:21:16 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		queue_push(t_queue *queue, t_list *elem)
{
	if (queue && elem)
	{
		if (queue->size == 0)
		{
			queue->head = elem;
			elem->next = queue->head;
			elem->prev = queue->head;
		}
		else
		{
			elem->prev = queue->head->prev;
			queue->head->prev->next = elem;
			queue->head->prev = elem;
			elem->next = queue->head;
			queue->head = elem;
		}
		queue->size += 1;
	}
}

t_list		*queue_pop(t_queue *queue)
{
	t_list	*elem;

	elem = NULL;
	if (queue && queue->size)
	{
		if (queue->size == 1)
		{
			elem = queue->head;
			queue->head = NULL;
			elem->prev = NULL;
			elem->next = NULL;
		}
		else
		{
			elem = queue->head->prev;
			elem->prev->next = elem->next;
			elem->next->prev = elem->prev;
			elem->next = NULL;
			elem->prev = NULL;
		}
		queue->size -= 1;
	}
	return (elem);
}

void		queue_clean(t_queue *queue)
{
	t_list	*tmp;
	t_list	*elem;
	size_t	size;

	if ((size = queue->size))
	{
		elem = queue->head;
		while (size--)
		{
			tmp = elem->next;
			ft_memdel((void **)&elem);
			elem = tmp;
		}
	}
	ft_memdel((void **)&queue);
}

t_queue		*queue_init(char name, t_list *head)
{
	t_queue	*queue;

	queue = (t_queue *)ft_memalloc(sizeof(t_queue));
	if (head)
		queue_push(queue, head);
	queue->name = name;
	queue->push = queue_push;
	queue->pop = queue_pop;
	return (queue);
}
