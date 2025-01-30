/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szemmour <szemmour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:52:20 by szemmour          #+#    #+#             */
/*   Updated: 2025/01/30 11:36:05 by szemmour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../libft/libft.h"

int	rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tail;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	head = *stack;
	tail = find_tail(head);
	*stack = head->next;
	(*stack)->prev = NULL;
	tail->next = head;
	head->prev = tail;
	head->next = NULL;
	return (1);
}

void	ra(t_stack **stack_a)
{
	if (rotate(stack_a))
		ft_putendl_fd("ra", 1);
}

void	rb(t_stack **stack_b)
{
	if (rotate(stack_b))
		ft_putendl_fd("rb", 1);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	if (rotate(stack_a) && rotate(stack_b))
		ft_putendl_fd("rr", 1);
}
