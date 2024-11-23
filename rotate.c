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

	if (*stack == NULL || (*stack)->next == NULL)
		return ;

	temp = *stack;
	*stack = (*stack)->next;
	temp->next = NULL;
	iterator = *stack;
	while (iterator->next != NULL)
		iterator = iterator->next;
	iterator->next = temp;
}

void	ra(t_stack **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_stack **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
