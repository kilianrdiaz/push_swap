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
	sort_3(&stack_a);
	print_stack(stack_a, stack_b);
	return (0);
}

