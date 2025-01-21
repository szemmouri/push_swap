/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szemmour <szemmour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:52:56 by szemmour          #+#    #+#             */
/*   Updated: 2025/01/20 13:26:27 by szemmour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_position(t_stack *stack)
{
	int	min_pos;
	int	min_val;
	int	pos;

	pos = 0;
	min_pos = 0;
	min_val = stack->data;
	while (stack)
	{
		if (stack->data < min_val)
		{
			min_val = stack->data;
			min_pos = pos;
		}
		stack = stack->next;
		pos++;
	}
	return (min_pos);
}

static void	move_min_to_top(t_stack **stack)
{
	int	min_pos;
	int	len;

	min_pos = find_min_position(*stack);
	len = stack_len(*stack);
	if (min_pos <= len / 2)
		while (min_pos--)
			ra(stack);
	else
		while (min_pos++ < len)
			rra(stack);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	len;

	len = stack_len(*stack_a);
	if (len > 5 || len < 4)
		return ;
	move_min_to_top(stack_a);
	pb(stack_a, stack_b);
	if (len == 5)
	{
		move_min_to_top(stack_a);
		pb(stack_a, stack_b);
	}
	sort_three(stack_a);
	pa(stack_a, stack_b);
	if (len == 5)
		pa(stack_a, stack_b);
}
