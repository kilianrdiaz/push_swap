/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pairs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroyo-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:23:51 by kroyo-di          #+#    #+#             */
/*   Updated: 2024/12/09 18:41:51 by kroyo-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../header/push_swap.h"

static void	pair_to_max(t_stack *a, t_stack *b)
{
	while (b != NULL)
	{
		if (b->value == get_max(b))
		{
			a->pair = b;
			break;
		}
		b = b->next;
	}
}

void	pair_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a;
	t_stack	*b;

	a = *stack_a;
	b = *stack_b;
	while (a != NULL)
	{
		b = *stack_b;
		if (a->value < get_min(b) || a->value > get_max(b))
			pair_to_max(a, b);
		else
		{
			a->pair = b;
			b = b->next;
			while (b != NULL)
			{
				if (b->value < a->value && b->value < a->pair->value)
					a->pair = b;
				b = b->next;
			}
		}
		a = a->next;
	}
}
