#include "../../includes/push_swap.h"

static int	reverse_rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tail;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	head = *stack;
	tail = find_tail(head);
	tail->prev->next = NULL;
	tail->next = head;
	tail->prev = NULL;
	head->prev = tail;
	*stack = tail;
	return (1);
}

int	rra(t_stack **stack_a)
{
	if (reverse_rotate(stack_a) == 0)
		return (0);
	ft_putendl_fd("rra", 1);
	return (1);
}

int	rrb(t_stack **stack_b)
{
	if (reverse_rotate(stack_b) == 0)
		return (0);
	ft_putendl_fd("rrb", 1);
	return (1);
}

int	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (reverse_rotate(stack_a) == 0 || reverse_rotate(stack_b) == 0)
		return (0);
	ft_putendl_fd("rrr", 1);
	return (1);
}
