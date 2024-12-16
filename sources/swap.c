/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroyo-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:42:00 by kroyo-di          #+#    #+#             */
/*   Updated: 2024/12/04 17:53:32 by kroyo-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	swap(t_stack *stack)
{
	int	temp;

	if (get_nelems(stack) <= 1)
		return ;
	temp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp;
	get_moves(stack);
}

void	sa(t_stack **a)
{
	swap(*a);
	ft_printf("sa\n");
}

void	sb(t_stack **b)
{
	swap(*b);
	ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	swap(*a);
	swap(*b);
	ft_printf("ss\n");
}
