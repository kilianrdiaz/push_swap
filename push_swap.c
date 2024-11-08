#include "push_swap.h"

void	get_stack(char **av, t_stack stack)
{
	int	i;

	i = 1;
	if (!check_args(av))
		print_error();
	while (av[i])
	{
		
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;
	
	if (ac == 1)
		return (0);
	get_stack(av, stack_a);
}
