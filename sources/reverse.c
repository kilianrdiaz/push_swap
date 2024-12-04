/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroyo-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:52:28 by kroyo-di          #+#    #+#             */
/*   Updated: 2024/12/04 17:52:40 by kroyo-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*iterator;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = *stack;
	iterator = *stack;
	while (iterator->next->next != NULL)
		iterator = iterator->next;
	*stack = iterator->next;
	iterator->next = NULL;
	(*stack)->next = temp;
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
	ft_printf("rra\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rra\n");
}
