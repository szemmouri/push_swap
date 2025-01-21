/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szemmour <szemmour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:53:43 by szemmour          #+#    #+#             */
/*   Updated: 2025/01/18 10:35:19 by szemmour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static t_stack	*find_biggest_node(t_stack *head)
{
	t_stack	*biggest_node;

	if (!head)
		return (NULL);
	biggest_node = head;
	while (head)
	{
		if (head->data > biggest_node->data)
			biggest_node = head;
		head = head->next;
	}
	return (biggest_node);
}

void	sort_three(t_stack **stack_a)
{
	t_stack	*biggest_node;

	biggest_node = find_biggest_node(*stack_a);
	if (biggest_node == *stack_a)
		ra(stack_a);
	else if (biggest_node == (*stack_a)->next)
		rra(stack_a);
	if ((*stack_a)->data > (*stack_a)->next->data)
		sa(stack_a);
}
