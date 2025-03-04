/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szemmour <szemmour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:51:52 by szemmour          #+#    #+#             */
/*   Updated: 2025/01/30 11:52:07 by szemmour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	int				data;
	int				index;
}					t_stack;

// stack utils
void				set_index(t_stack **stack_a);
int					is_sorted(t_stack *stack_a);
int					find_max_idx(t_stack *stack);
t_stack				*ft_create_node(int data);
void				ft_push_back(t_stack **head, int data);
void				ft_push_front(t_stack **head, int data);
int					stack_len(t_stack *head);
t_stack				*find_tail(t_stack *head);
void				free_stack(t_stack **stack);
void				free_argv(char **argv);

// stack init
void				stack_init(t_stack **a, char **argv);
void				free_stack(t_stack **stack);
void				free_errors(t_stack **a);

// operations
int					swap(t_stack **stack);
void				sa(t_stack **stack_a);
void				sb(t_stack **stack_b);
void				ss(t_stack **stack_a, t_stack **stack_b);

int					push(t_stack **stack_to, t_stack **stack_from);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);

int					rotate(t_stack **stack);
void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);

int					reverse_rotate(t_stack **stack);
void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);

// Sorting
void				sort_three(t_stack **stack_a);
void				sort_five(t_stack **stack_a, t_stack **stack_b);

void				sort_stack(t_stack **stack_a, t_stack **stack_b,
						int num_chunks);
void				sort(t_stack **stack_a, t_stack **stack_b);
void				move_max_to_a(t_stack **stack_a, t_stack **stack_b);
#endif
