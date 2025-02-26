/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szemmour <szemmour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:52:49 by szemmour          #+#    #+#             */
/*   Updated: 2025/02/26 12:35:11 by szemmour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../libft/libft.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**strs;
	int		i;

	i = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	while (argv[++i])
	{
		strs = ft_split(argv[i], ' ');
		stack_init(&stack_a, strs);
	}
	if (!is_sorted(stack_a))
		sort(&stack_a, &stack_b);
	move_max_to_a(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_argv(strs);
	return (0);
}
