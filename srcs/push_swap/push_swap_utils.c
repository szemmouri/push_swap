/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szemmour <szemmour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 09:25:38 by szemmour          #+#    #+#             */
/*   Updated: 2025/01/20 10:11:23 by szemmour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../libft/libft.h"

int	is_sorted(t_stack *stack_a)
{
	while (stack_a->next)
	{
		if (stack_a->data > stack_a->next->data)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
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

void	free_stack(t_stack **stack)
{
	t_stack	*cur;
	t_stack	*tmp;

	cur = *stack;
	if (!stack)
		return ;
	while (cur)
	{
		tmp = cur;
		tmp->data = 0;
		cur = cur->next;
		free(tmp);
	}
	*stack = NULL;
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int	len;

	set_index(stack_a);
	len = stack_len(*stack_a);
	if (len == 2)
		sa(stack_a);
	else if (len == 3)
		sort_three(stack_a);
	else if (len == 5 || len == 4)
		sort_five(stack_a, stack_b);
	else if (len <= 100)
		sort_stack(stack_a, stack_b, 15);
	else if (len > 100 && len <= 500)
		sort_stack(stack_a, stack_b, 35);
	else
		sort_stack(stack_a, stack_b, 45);
}

void	free_argv(char **argv)
{
	int	i;

	i = 0;
	if (!argv)
		return ;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}
