#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	//t_stack	*stack_b;
	
	if (ac == 1)
		return (0);
	stack_a = NULL;
	//stack_b = NULL;
	get_stack(ac, av, &stack_a);
	
	//TESTS
	t_stack *top;
	top = stack_a;
	ft_printf("STACK A\n");
	while (stack_a != NULL)
	{
		ft_printf("%d\n", stack_a->value);
		stack_a = stack_a->next;
	}
	stack_a = top;
	sa(&stack_a);
	ft_printf("\nSTACK A\n");
	while (stack_a != NULL)
	{
		ft_printf("%d\n", stack_a->value);
		stack_a = stack_a->next;
	}
	return (0);
}

