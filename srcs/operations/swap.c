/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szemmour <szemmour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:54:23 by szemmour          #+#    #+#             */
/*   Updated: 2025/01/30 11:38:02 by szemmour         ###   ########.fr       */
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

void	sa(t_stack **stack_a)
{
	if (swap(stack_a))
		ft_putendl_fd("sa", 1);
}

void	sb(t_stack **stack_b)
{
	if (swap(stack_b))
		ft_putendl_fd("sb", 1);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !*stack_a || !stack_b || !*stack_b)
		return ;
	if (swap(stack_a) && swap(stack_b))
		ft_putendl_fd("ss", 1);
}
