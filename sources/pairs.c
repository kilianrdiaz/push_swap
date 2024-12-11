/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pairs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroyo-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:23:51 by kroyo-di          #+#    #+#             */
/*   Updated: 2024/12/11 18:28:21 by kroyo-di         ###   ########.fr       */
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
			break ;
		}
		b = b->next;
	}
}

static int	find_first_pair(t_stack *a, t_stack *pair)
{
	if (pair->value < a->value)
	{
		a->pair = pair;
		return (1);
	}
	return (0);
}

void	pair(t_stack *a, t_stack *b)
{
	t_stack	*tmp;

	tmp = b;
	while (a != NULL)
	{
		b = tmp;
		if (a->value < get_min(b) || a->value > get_max(b))
			pair_to_max(a, b);
		else
		{
			while (b != NULL)
			{
				if (find_first_pair(a, b))
					break ;
				b = b->next;
			}
			while (b != NULL)
			{
				if (b->value < a->value && b->value > a->pair->value)
					a->pair = b;
				b = b->next;
			}
		}
		a = a->next;
	}
}
