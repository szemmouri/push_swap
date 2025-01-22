/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szemmour <szemmour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:20:50 by szemmour          #+#    #+#             */
/*   Updated: 2025/01/20 18:10:12 by szemmour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	cmp_moves(char *line)
{
	return (ft_strncmp(line, "sa\n", 3) || ft_strncmp(line, "sb\n", 3)
		|| ft_strncmp(line, "ss\n", 3) || ft_strncmp(line, "pa\n", 3)
		|| ft_strncmp(line, "pb\n", 3) || ft_strncmp(line, "ra\n", 3)
		|| ft_strncmp(line, "rb\n", 3) || ft_strncmp(line, "rr\n", 3)
		|| ft_strncmp(line, "rra\n", 4) || ft_strncmp(line, "rrb\n", 4)
		|| ft_strncmp(line, "rrr\n", 4));
}

static void	excute_moves(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (ft_strncmp(line, "sa\n", 3) || ft_strncmp(line, "ss\n", 3))
		swap(stack_a);
	if (ft_strncmp(line, "sb\n", 3) || ft_strncmp(line, "ss\n", 3))
		swap(stack_b);
	if (ft_strncmp(line, "pa\n", 3))
		push(stack_a, stack_b);
	if (ft_strncmp(line, "pb\n", 3))
		push(stack_b, stack_a);
	if (ft_strncmp(line, "ra\n", 3) || ft_strncmp(line, "rr\n", 3))
		rotate(stack_a);
	if (ft_strncmp(line, "rb\n", 3) || ft_strncmp(line, "rr\n", 3))
		rotate(stack_b);
	if (ft_strncmp(line, "rra\n", 4) || ft_strncmp(line, "rrr\n", 4))
		reverse_rotate(stack_a);
	if (ft_strncmp(line, "rrb\n", 4) || ft_strncmp(line, "rrr\n", 4))
		reverse_rotate(stack_b);
}

static void	check_moves(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (cmp_moves(line))
			excute_moves(stack_a, stack_b, line);
		else
		{
			ft_putendl_fd("Error", 2);
			free(line);
			free_stack(stack_a);
			free_stack(stack_b);
			exit(1);
		}
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(*stack_a) && !*stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

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
	check_moves(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	if (argc == 2)
		free_argv(argv);
	return (0);
}
