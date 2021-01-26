/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 23:51:16 by acyrenna          #+#    #+#             */
/*   Updated: 2020/09/14 00:57:03 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		stack_clean(t_stack *stack)
{
	t_list	*tmp;
	t_list	*elem;
	size_t	size;

	if ((size = stack->size))
	{
		elem = stack->head;
		while (size--)
		{
			tmp = elem->next;
			ft_memdel((void **)&elem);
			elem = tmp;
		}
	}
	ft_memdel((void **)&stack);
}

void		stack_push(t_stack *stack, t_list *elem)
{
	if (stack && elem)
	{
		if (stack->size == 0)
		{
			stack->head = elem;
			elem->next = stack->looped ? stack->head : NULL;
			elem->prev = stack->looped ? stack->head : NULL;
		}
		else
		{
			elem->prev = stack->looped ? stack->head->prev : NULL;
			stack->looped ? stack->head->prev->next = elem : NULL;
			stack->head->prev = elem;
			elem->next = stack->head;
			stack->head = elem;
		}
		stack->size += 1;
	}
}

t_list 		*stack_pop(t_stack *stack)
{
	t_list 	*elem;

	elem = NULL;
	if (stack && stack->size)
	{
		if (stack->size == 1)
		{
			elem = stack->head;
			stack->head = NULL;
			elem->prev = NULL;
			elem->next = NULL;
		}
		else
		{
			elem = stack->head;
			stack->head = stack->head->next;
			elem->prev->next = stack->looped ? elem->next : NULL;
			elem->next->prev = stack->looped ? elem->prev : NULL;
			elem->next = NULL;
			elem->prev = NULL;
		}
		stack->size -= 1;
	}
	return (elem);
}

void		stack_lpush(t_stack *stack, long elem)
{
	t_list *l;
	long 	*content;

	content = (long *)malloc(sizeof(long));
	*content = elem;
	l = ft_lstnew((void *)content, sizeof(elem));
	free(content);
	stack_push(stack, l);
}

t_stack		*stack_init(char name, t_list *head, unsigned char looped)
{
	t_stack	*stack;

	stack = (t_stack *)ft_memalloc(sizeof(t_stack));
	if (head)
		stack_push(stack, head);
	stack->looped = looped;
	stack->name = name;
	stack->pop = stack_pop;
	stack->push = stack_push;
	return (stack);
}
