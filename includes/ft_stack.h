#ifndef COREWAR_FT_STACK_H
# define COREWAR_FT_STACK_H

#include "libft.h"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef struct		s_stack
{
	size_t 			size;
	t_list			*head;
	unsigned char	looped;
	char 			name;
	void 			(*push)(struct s_stack *stack, t_list *lst);
	t_list			*(*pop)(struct s_stack *stack);
}					t_stack;

void		stack_clean(t_stack *stack, void (*del)(void *, size_t));
void		stack_lpush(t_stack *stack, long elem);
t_stack		*stack_init(char name, t_list *head, unsigned char looped);
void		stack_push(t_stack *stack, t_list *elem);
t_list 		*stack_pop(t_stack *stack);

#endif
