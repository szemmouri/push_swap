/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szemmour <szemmour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:53:30 by szemmour          #+#    #+#             */
/*   Updated: 2025/01/20 13:26:34 by szemmour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	*cpy_stack(t_stack *stack, int len)
{
	int	*arr;
	int	i;

	i = 0;
	arr = malloc(sizeof(int) * len);
	if (!arr)
		return (NULL);
	while (i < len)
	{
		arr[i] = stack->data;
		stack = stack->next;
		i++;
	}
	return (arr);
}

int	*sort_arr(t_stack *stack, int len)
{
	int	*arr;
	int	tmp;
	int	i;
	int	j;

	i = 0;
	arr = cpy_stack(stack, len);
	while (i < len)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (arr);
}

void	set_index(t_stack **stack_a)
{
	int		i;
	int		len;
	int		*arr;
	t_stack	*tmp;

	tmp = (*stack_a);
	len = stack_len(*stack_a);
	arr = sort_arr(*stack_a, len);
	while (tmp)
	{
		i = 0;
		while (i < len)
		{
			if (arr[i] == tmp->data)
			{
				tmp->index = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
	free(arr);
	arr = NULL;
}

void	move_max_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int	index;
	int	size;

	while (*stack_b)
	{
		index = find_max_idx(*stack_b);
		size = stack_len(*stack_b) / 2;
		if (index == 0)
			pa(stack_a, stack_b);
		else if (index > size)
			rrb(stack_b);
		else if (index <= size)
			rb(stack_b);
	}
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b, int end)
{
	int	start;

	start = 0;
	while (*stack_a)
	{
		if ((*stack_a)->index >= start && (*stack_a)->index <= end)
		{
			pb(stack_a, stack_b);
			start++;
			end++;
		}
		else if ((*stack_a)->index < start)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			start++;
			end++;
		}
		else
			ra(stack_a);
	}
}
