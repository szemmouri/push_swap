#include "push_swap.h"

int find_min_position(t_stack *stack)
{
    int pos = 0;
    int min_pos = 0;
    int min_val = stack->data;

    while (stack)
    {
        if (stack->data < min_val)
        {
            min_val = stack->data;
            min_pos = pos;
        }
        stack = stack->next;
        pos++;
    }
    return min_pos;
}

void move_min_to_top(t_stack **stack)
{
    int min_pos = find_min_position(*stack);
    int len = stack_len(*stack);

    if (min_pos <= len / 2) // Closer to the top
    {
        while (min_pos--)
            ra(stack);
    }
    else // Closer to the bottom
    {
        while (min_pos++ < len)
            rra(stack);
    }
}

void sort_five(t_stack **stack_a, t_stack **stack_b)
{
    if (!stack_a || !*stack_a || stack_len(*stack_a) != 5)
        return;

    move_min_to_top(stack_a);
    pb(stack_a, stack_b);

    move_min_to_top(stack_a);
    pb(stack_a, stack_b);

    sort_three(stack_a);

    pa(stack_a, stack_b);
    pa(stack_a, stack_b);

}