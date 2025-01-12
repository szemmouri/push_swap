#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	int				data;
}					t_stack;

// stack utils
t_stack				*ft_create_node(int data);
void				ft_push_back(t_stack **head, int data);
int					stack_len(t_stack *head);
t_stack				*find_biggest_node(t_stack *head);
t_stack				*find_tail(t_stack *head);

// operations
int					sa(t_stack **stack_a);
int					sb(t_stack **stack_b);
int					ss(t_stack **stack_a, t_stack **stack_b);

int					pa(t_stack **stack_a, t_stack **stack_b);
int					pb(t_stack **stack_a, t_stack **stack_b);

int					ra(t_stack **stack_a);
int					rb(t_stack **stack_b);
int					rr(t_stack **stack_a, t_stack **stack_b);

int					rra(t_stack **stack_a);
int					rrb(t_stack **stack_b);
int					rrr(t_stack **stack_a, t_stack **stack_b);

// stack init
int					is_sorted(t_stack *stack_a);
void				stack_init(t_stack **a, char **argv);

// Sorting
void				sort_three(t_stack **stack_a);

#endif
