/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szemmour <szemmour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:52:15 by szemmour          #+#    #+#             */
/*   Updated: 2025/01/30 11:35:04 by szemmour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../libft/libft.h"

int	reverse_rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tail;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	head = *stack;
	tail = find_tail(head);
	tail->prev->next = NULL;
	tail->next = head;
	tail->prev = NULL;
	head->prev = tail;
	*stack = tail;
	return (1);
}

void	rra(t_stack **stack_a)
{
	if (reverse_rotate(stack_a))
		ft_putendl_fd("rra", 1);
}

void	rrb(t_stack **stack_b)
{
	if (reverse_rotate(stack_b))
		ft_putendl_fd("rrb", 1);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (reverse_rotate(stack_a) && reverse_rotate(stack_b))
		ft_putendl_fd("rrr", 1);
}
