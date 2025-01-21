/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szemmour <szemmour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:52:49 by szemmour          #+#    #+#             */
/*   Updated: 2025/01/21 12:51:23 by szemmour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../libft/libft.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	argv = &argv[1];
	if (argc == 2)
		argv = ft_split(*argv, ' ');
	stack_init(&stack_a, argv);
	if (!is_sorted(stack_a))
		sort(&stack_a, &stack_b);
	move_max_to_a(&stack_a, &stack_b);
	free_stack(&stack_a);
	if (argc == 2)
		free_argv(argv);
	return (0);
}
