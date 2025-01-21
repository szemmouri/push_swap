/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szemmour <szemmour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:46:14 by szemmour          #+#    #+#             */
/*   Updated: 2025/01/18 13:18:19 by szemmour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_create_node(int data)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	ft_push_back(t_stack **head, int data)
{
	t_stack	*last_node;
	t_stack	*new;

	if (!head)
		return ;
	new = ft_create_node(data);
	if (!new)
		return ;
	if (!*head)
		*head = new;
	else
	{
		last_node = find_tail(*head);
		last_node->next = new;
		new->prev = last_node;
	}
}

void	ft_push_front(t_stack **head, int data)
{
	t_stack	*new;

	if (!head)
		return ;
	new = ft_create_node(data);
	if (!new)
		return ;
	if (!*head)
		*head = new;
	else
	{
		new->next = *head;
		(*head)->prev = new;
		(*head) = new;
	}
}

t_stack	*find_tail(t_stack *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

int	find_max_idx(t_stack *stack)
{
	int	i;
	int	max_idx;
	int	tmp;

	max_idx = 0;
	i = 0;
	if (!stack)
		return (-1);
	tmp = stack->data;
	while (stack)
	{
		if (tmp < stack->data)
		{
			max_idx = i;
			tmp = stack->data;
		}
		i++;
		stack = stack->next;
	}
	return (max_idx);
}
