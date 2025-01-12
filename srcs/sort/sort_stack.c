#include "../../includes/push_swap.h"

int	find_smallest(t_stack *head)
{
	int	smallest;

	if (!head)
		return (NULL);
	smallest = head->data;
	while (head)
	{
		if (head->data < smallest)
			smallest = head;
		head = head->next;
	}
	return (smallest);
}

int pos_finder(t_stack *head, int smallest)
{
    int pos;

    pos = 0;
    if(!head)
        return (0);
    while (head)
    {
        pos++;
        if(head->data == smallest)
            return pos;
        head = head->next;
    } 
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b, int operation_count)
{

}