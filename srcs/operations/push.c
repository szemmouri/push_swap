#include "../../includes/push_swap.h"

static int	push(t_stack **stack_to, t_stack **stack_from)
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

int	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (push(stack_a, stack_b) == 0)
		return (0);
	ft_putendl_fd("pa", 1);
	return (1);
}

int	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (push(stack_b, stack_a) == 0)
		return (0);
	ft_putendl_fd("pb", 1);
	return (1);
}
