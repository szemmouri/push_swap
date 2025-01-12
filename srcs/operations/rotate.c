#include "../../includes/push_swap.h"

static int	rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tail;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	head = *stack;
	tail = find_tail(head);
	// Update the head
	*stack = head->next;
	(*stack)->prev = NULL;
	// Move the old head to the tail
	tail->next = head;
	head->prev = tail;
	head->next = NULL;
	return (1);
}

int	ra(t_stack **stack_a)
{
	if (rotate(stack_a) == 0)
		return (0);
	ft_putendl_fd("ra", 1);
	return (1);
}

int	rb(t_stack **stack_b)
{
	if (rotate(stack_b) == 0)
		return (0);
	ft_putendl_fd("rb", 1);
	return (1);
}

int	rr(t_stack **stack_a, t_stack **stack_b)
{
	if (rotate(stack_a) == 0 || rotate(stack_b) == 0)
		return (0);
	ft_putendl_fd("rr", 1);
	return (1);
}
