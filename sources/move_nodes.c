/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroyo-di <kroyo-di@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:16:42 by kroyo-di          #+#    #+#             */
/*   Updated: 2024/12/17 20:26:09 by kroyo-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	calculate_move(t_stack *node, t_stack **a, t_stack **b)
{
	int		rr;
	int		rrr;
	int		ra_rrb;
	int		rra_rb;
	int		move;

	if (node_pos(node->value, *a) == 0 || node_pos(node->pair->value, *b) == 0)
		return (0);
	rr = ft_max(node->rot, node->pair->rot);
	rrr = ft_max(node->rev, node->pair->rev);
	ra_rrb = node->rot + node->pair->rev;
	rra_rb = node->rev + node->pair->rot;
	move = ft_min(ft_min(rr, rrr), ft_min(ra_rrb, rra_rb));
	if (move == rr)
		return (1);
	else if (move == rrr)
		return (2);
	else
		return (3);
}

void	move_separate_a(t_stack *node, t_stack **a, t_stack **b)
{
	while (node != *a)
	{
		if (node->rot <= node->rev)
			ra(a);
		else
			rra(a);
	}
	while (node->pair != *b && *b != NULL)
	{
		if (node->pair->rot <= node->pair->rev)
			rb(b);
		else
			rrb(b);
	}
}

void	move_separate_b(t_stack *node, t_stack **a, t_stack **b)
{
	while (node != *b)
	{
		if (node->rot <= node->rev)
			rb(b);
		else
			rrb(b);
	}
	while (node->pair != *a)
	{
		if (node->pair->rot <= node->pair->rev)
			ra(a);
		else
			rra(a);
	}
}

void	move_together(t_stack *node, t_stack **a, t_stack **b, int rot)
{
	t_stack	*pair;

	pair = node->pair;
	if (rot)
	{
		while (node != *a && pair != *b)
			rr(a, b);
	}
	else
	{
		while (node != *a && pair != *b)
			rrr(a, b);
	}
	move_separate_a(node, a, b);
}

void	move_choose(t_stack *node, t_stack **a, t_stack **b)
{
	t_stack	*pair;
	int		ra_rrb;
	int		rra_rb;

	pair = node->pair;
	ra_rrb = node->rot + node->pair->rev;
	rra_rb = node->rev + node->pair->rot;
	if (ra_rrb <= rra_rb)
	{
		if ((pair->rot - node->rot) <= pair->rev)
			move_together(node, a, b, 1);
		else
			move_separate_a(node, a, b);
	}
	else
	{
		if ((pair->rev - node->rev) <= pair->rot)
			move_together(node, a, b, 0);
		else
			move_separate_a(node, a, b);
	}
}
