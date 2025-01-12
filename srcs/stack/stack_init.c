#include "../../includes/push_swap.h"

static int	ft_is_str_digits(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		while (av[i] == ' ' || av[i] == '\t')
			i++;
		if (av[i] == '-' || av[i] == '+')
			i++;
		while (av[i] >= '0' && av[i] <= '9')
			i++;
		if (ft_isdigit(av[i]) == 0)
			return (0);
	}
	return (1);
}

static long	ft_atol(const char *str)
{
	long	result;
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	return (result * sign);
}
static int	check_repetition(t_stack *a, int nbr)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->data == nbr)
			return (0);
		a = a->next;
	}
	return (1);
}

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

void	stack_init(t_stack **a, char **argv)
{
	long	nbr;
	int		i;

	i = 1;
	while (argv[i])
	{
		if (ft_isdigit(argv[i]) == 0)
		{
			ft_putendl_fd("Error", 2);
			return ;
		}
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
		{
			ft_putendl_fd("Error", 2);
			return ;
		}
		if (check_repetition(*a, (int)nbr))
		{
			ft_putendl_fd("Error", 2);
			return ;
		}
		ft_push_back(&a, (int)nbr);
		i++;
	}
}
