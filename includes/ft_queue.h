/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 15:20:40 by acyrenna          #+#    #+#             */
/*   Updated: 2021/02/13 15:22:18 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_FT_QUEUE_H
# define COREWAR_FT_QUEUE_H

# include "libft.h"

typedef struct		s_queue
{
	char			name;
	size_t			size;
	struct s_list	*head;
	void			(*push)(struct s_queue *, t_list *);
	t_list			*(*pop)(struct s_queue *);
}					t_queue;

t_queue				*queue_init(char name, t_list *head);
void				queue_clean(t_queue *queue);
t_list				*queue_pop(t_queue *queue);
void				queue_push(t_queue *queue, t_list *elem);

#endif
