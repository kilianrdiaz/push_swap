/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroyo-di <kroyo-di@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:43:31 by kroyo-di          #+#    #+#             */
/*   Updated: 2024/12/13 22:59:22 by kroyo-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	move_target(t_stack **a, t_stack **b, t_stack *target)
{
	target = get_cheapest(*a, *b);
}

void	sort_long(t_stack **a, t_stack **b)
{
	t_stack	*target;

	pb(a, b);
	pb(a, b);
	get_moves(a);
	get_moves(b);
	while (get_nelems(*a) > 3)
	{
		pair_a(a, b);
		move_target(a, b);
	}
	sort_3(a);
	while (*b != NULL)
	{
	}
}

void	sort_4(t_stack **a, t_stack **b)
{
	t_stack	*node;

	node = *a;
	while (node->value != get_min(*a))
		node = node->next;
	if (node->rot < node->rev)
	{
		while (node->rot != 0)
		{
			ra(a);
			get_moves(*a);
		}
	}
	else
	{
		while (node->rev != 0)
		{
			rra(a);
			get_moves(*a);
		}
	}
	pb(a, b);
	sort_3(a);
	pa(a, b);
}

void	sort(t_stack **a, t_stack **b)
{
	if (is_sorted(*a) || *a == NULL)
		return ;
	if (get_nelems(*a) < 5)
	{
		if (get_nelems(*a) == 2)
			sa(a);
		else if (get_nelems(*a) == 4)
			sort_4(a, b);
		else
			sort_3(a);
	}
	else
		sort_long(a, b);
}
