/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szemmour <szemmour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:52:09 by szemmour          #+#    #+#             */
/*   Updated: 2025/01/30 11:33:54 by szemmour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../libft/libft.h"

int	push(t_stack **stack_to, t_stack **stack_from)
{
	t_stack	*stack_top;

	if (!stack_from || !*stack_from || !stack_to)
		return (0);
	stack_top = *stack_from;
	*stack_from = stack_top->next;
	if (*stack_from)
		(*stack_from)->prev = NULL;
	ft_push_front(stack_to, stack_top->data);
	free(stack_top);
	stack_top = NULL;
	return (1);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (push(stack_a, stack_b))
		ft_putendl_fd("pa", 1);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (push(stack_b, stack_a))
		ft_putendl_fd("pb", 1);
}
