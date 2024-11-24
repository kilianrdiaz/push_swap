/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroyo-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:42:17 by kroyo-di          #+#    #+#             */
/*   Updated: 2024/11/22 19:28:18 by kroyo-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	
	if (ac == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	get_stack(ac, av, &stack_a);
	
	//TESTS
	print_stack(stack_a, stack_b);
	sa(&stack_a);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	rr(&stack_a, &stack_b);
	rrr(&stack_a, &stack_b);
	sa(&stack_a);
	pa(&stack_a, &stack_b);
	pa(&stack_a, &stack_b);
	pa(&stack_a, &stack_b);
	print_stack(stack_a, stack_b);
	return (0);
}

