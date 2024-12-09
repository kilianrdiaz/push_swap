/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroyo-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:42:17 by kroyo-di          #+#    #+#             */
/*   Updated: 2024/12/09 19:51:02 by kroyo-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack *tmp;

	if (ac == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	get_stack(ac, av, &stack_a);
	print_stack(stack_a, stack_b);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	print_stack(stack_a, stack_b);
	pair_a(&stack_a, &stack_b);
	tmp = stack_a;
	/*while (tmp)
	{
		ft_printf("%d -> %d\n", tmp->value ,tmp->pair->value);
		tmp = tmp->next;
	}*/
	ft_printf("%d", get_cheapest(stack_a, stack_b)->value);
	//TESTS
	/*print_stack(stack_a, stack_b);
	sort_3(&stack_a);
	print_stack(stack_a, stack_b);*/
	return (0);
}

