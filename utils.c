/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroyo-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:42:54 by kroyo-di          #+#    #+#             */
/*   Updated: 2024/11/22 19:36:15 by kroyo-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_nelems(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack != NULL)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

void	delete_node(t_stack **node)
{
	t_stack	*temp;

	temp = *node;
	*node = (*node)->next;
	free(temp);
}

void	print_stack(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("\nSTACK A  |  STACK B\n");
	while (stack_a != NULL || stack_b != NULL)
	{
		if (stack_a != NULL)
		{
			ft_printf("%d", stack_a->value);
			stack_a = stack_a->next;
		}
		ft_printf("\t |  ");
		if (stack_b != NULL)
		{
			ft_printf("%d", stack_b->value);
			stack_b = stack_b->next;
		}
		ft_printf("\n");
	}
	ft_printf("\n");
}
