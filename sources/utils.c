/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroyo-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:42:54 by kroyo-di          #+#    #+#             */
/*   Updated: 2024/12/11 17:35:27 by kroyo-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

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

int	get_min(t_stack *stack)
{
	int	min;

	min = stack->value;
	while (stack != NULL)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

int	get_max(t_stack *stack)
{
	int	max;

	max = stack->value;
	while (stack != NULL)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

//BORRAR ANTES DE ENTREGAR
void	print_stack(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("\nSTACK A  |  STACK B\n");
	while (stack_a != NULL || stack_b != NULL)
	{
		if (stack_a != NULL)
		{
			ft_printf("%d->%d", stack_a->value, stack_a->pair->value);
			stack_a = stack_a->next;
		}
		ft_printf("\t |  ");
		if (stack_b != NULL)
		{
			ft_printf("%d->%d", stack_b->value, stack_b->pair->value);
			stack_b = stack_b->next;
		}
		ft_printf("\n");
	}
	ft_printf("\n");
}
