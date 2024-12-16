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

void	sort_long(t_stack **a, t_stack **b)
{
	pb(a, b);
	pb(a, b);
	get_moves(*a);
	get_moves(*b);
	while (get_nelems(*a) > 3)
	{
		pair_a(*a, *b);
		move_to_top(a, b);
		pb(a, b);
	}
	sort_3(a);
	while (*b != NULL)
	{
		pair_b(*a, *b);
		move_separate_b(*b, a, b);
		pa(a, b);
	}
	move_separate_a(find_node(get_min(*a), *a), a, b);
}

void	sort_4(t_stack **a, t_stack **b)
{
	t_stack	*node;

	node = *a;
	while (node->value != get_min(*a))
		node = node->next;
	if (node->rot < node->rev)
	{
		while (node != *a)
		{
			ra(a);
			get_moves(*a);
		}
	}
	else
	{
		while (node != *a)
		{
			rra(a);
			get_moves(*a);
		}
	}
	if (is_sorted(*a))
		return ;
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
