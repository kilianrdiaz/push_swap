/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroyo-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:53:04 by kroyo-di          #+#    #+#             */
/*   Updated: 2024/12/04 17:53:18 by kroyo-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	sort_3(t_stack **stack)
{
	if (is_sorted(*stack))
		return ;
	else if (get_min(*stack) == (*stack)->value)
	{
		rra(stack);
		sa(stack);
	}
	else if (get_max(*stack) == (*stack)->value)
	{
		ra(stack);
		if (!is_sorted(*stack))
			sa(stack);
	}
	else
	{
		if ((*stack)->next->value == get_min(*stack))
			sa(stack);
		else
			rra(stack);
	}
}
