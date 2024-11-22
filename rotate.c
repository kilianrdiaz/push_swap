/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroyo-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:41:48 by kroyo-di          #+#    #+#             */
/*   Updated: 2024/11/22 20:13:44 by kroyo-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack *iterator;

	if (*stack == NULL || *stack->next == NULL)
		return ;

	temp = *stack;
	*stack = (*stack)->next;
	while (stack->next != NULL)
		stack = stack->next;
	*stack->next = temp;
	temp->next = NULL;
}

void	ra(t_stack **a)
{
	
}

void	rb(t_stack **b)
{

}

void	rr(t_stack **a, t_stack **b)
{

}
