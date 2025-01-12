/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szemmour <szemmour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:46:14 by szemmour          #+#    #+#             */
/*   Updated: 2025/01/12 11:26:33 by szemmour         ###   ########.fr       */
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

t_stack	*find_biggest_node(t_stack *head)
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

int	stack_len(t_stack *head)
{
	int	count;

	if (!head)
		return (0);
	count = 0;
	while (head)
	{
		count++;
		head = head->next;
	}
	return (count);
}

t_stack	*find_tail(t_stack *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}
