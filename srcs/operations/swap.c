/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szemmour <szemmour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:54:23 by szemmour          #+#    #+#             */
/*   Updated: 2025/01/19 12:22:56 by szemmour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../libft/libft.h"

int	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (stack_len(*stack) < 2)
		return (0);
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	first->prev = second;
	if (first->next)
		first->next->prev = first;
	second->next = first;
	second->prev = NULL;
	*stack = second;
	return (1);
}

int	sa(t_stack **stack_a)
{
	if (!stack_a || !*stack_a)
		return (0);
	if (swap(stack_a) == 0)
		return (0);
	ft_putendl_fd("sa", 1);
	return (1);
}

int	sb(t_stack **stack_b)
{
	if (!stack_b || !*stack_b)
		return (0);
	if (swap(stack_b) == 0)
		return (0);
	ft_putendl_fd("sb", 1);
	return (1);
}

int	ss(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !*stack_a || !stack_b || !*stack_b)
		return (0);
	if (swap(stack_a) == 0 || swap(stack_b) == 0)
		return (0);
	ft_putendl_fd("ss", 1);
	return (1);
}
