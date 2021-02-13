/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 23:51:16 by acyrenna          #+#    #+#             */
/*   Updated: 2021/02/13 15:17:23 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		stack_clean(t_stack *stack, void (*del)(void *, size_t))
{
	size_t	size;
	t_list	*lst;

	if (stack->looped)
	{
		lst = stack->head;
		size = stack->size;
		while (lst && size--)
		{
			del(lst, lst->content_size);
			lst = lst->next;
		}
	}
	else
		ft_lstdel(&stack->head, del);
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

t_list		*stack_pop(t_stack *stack)
{
	t_list	*elem;

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
	t_list	*l;
	long	*content;

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
