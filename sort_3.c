#include "push_swap.h"

void	sort_3(t_stack **stack)
{
	if (check_sorted(*stack))
		return ;
	else if (get_min(*stack) == (*stack)->value)
	{
		rra(stack);
		sa(stack);
	}
	else if (get_max(*stack) == (*stack)->value)
	{
		ra(stack);
		if (!check_sorted(*stack))
			sa(stack);
	}
	else
	{
		if ((*stack)->next->value == get_min(*stack))
			sa(stack);
		else
			rra(stack);
	}
}
