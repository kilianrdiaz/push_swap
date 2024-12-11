/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroyo-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:23:51 by kroyo-di          #+#    #+#             */
/*   Updated: 2024/12/11 19:02:59 by kroyo-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	get_moves(t_stack *stack)
{
	t_stack	*top;

	top = stack;
	while (stack != NULL)
	{
		stack->rot = node_pos(stack->value, top);
		stack->rev = get_nelems(top) - node_pos(stack->value, top);
		stack = stack->next;
	}
}

static int	ft_ra_rrb(t_stack *node, t_stack *pair)
{
	if ((pair->rot - node->rot) <= pair->rev)
		return (pair->rot);
	else
		return (node->rot + pair->rev);
}

static int	ft_rra_rb(t_stack *node, t_stack *pair)
{
	if ((pair->rev - node->rev) <= pair->rot)
		return (pair->rev);
	else
		return (node->rev + pair->rot);
}

int	calculate_cost(t_stack *node, t_stack *a, t_stack *b)
{
	t_stack	*pair;
	int		rr;
	int		rrr;
	int		ra_rrb;
	int		rra_rb;

	pair = node->pair;
	if (node_pos(node->value, a) == 0)
		return (ft_min(pair->rot, pair->rev) + 1);
	else if (node_pos(pair->value, b) == 0)
		return (ft_min(node->rot, node->rev) + 1);
	rr = ft_max(node->rot, pair->rot);
	rrr = ft_max(node->rev, pair->rev);
	ra_rrb = ft_ra_rrb(node, pair);
	rra_rb = ft_rra_rb(node, pair);
	return (ft_min(ft_min(rr, rrr), ft_min(ra_rrb, rra_rb)) + 1);
}

t_stack	*get_cheapest(t_stack *a, t_stack *b)
{
	t_stack	*node;
	t_stack	*cheapest;
	int		moves;

	node = a;
	get_moves(a);
	get_moves(b);
	moves = calculate_cost(node, a, b);
	cheapest = a;
	a = a->next;
	while (a)
	{
		if (calculate_cost(node, a, b) < moves)
		{
			moves = calculate_cost(node, a, b);
			cheapest = a;
		}
		a = a->next;
	}
	return (cheapest);
}
