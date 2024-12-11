/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroyo-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:42:17 by kroyo-di          #+#    #+#             */
/*   Updated: 2024/12/11 17:27:35 by kroyo-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack *cheap;
	t_stack *tmp;

	if (ac == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	get_stack(ac, av, &stack_a);
	//print_stack(stack_a, stack_b);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	pair(&stack_a, &stack_b);
	print_stack(stack_a, stack_b);
	cheap = get_cheapest(stack_a, stack_b);
	tmp = stack_a;
	while (tmp)
	{
		ft_printf("%d - %d\n", tmp->rot, tmp->rev);
		tmp = tmp->next;
	}
	ft_printf("Cheapest value: %d\n", cheap->value);
	return (0);
}

