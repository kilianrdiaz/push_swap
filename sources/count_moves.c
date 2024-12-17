/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroyo-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:23:51 by kroyo-di          #+#    #+#             */
/*   Updated: 2024/12/17 20:13:30 by kroyo-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	move_to_top(t_stack **a, t_stack **b)
{
	t_stack	*target;
	int		movement;

	target = get_cheapest(*a, *b);
	movement = calculate_move(target, a, b);
	if (movement == 0)
		move_separate_a(target, a, b);
	else if (movement == 1)
		move_together(target, a, b, 1);
	else if (movement == 2)
		move_together(target, a, b, 0);
	else
		move_choose(target, a, b);
}

void	get_moves(t_stack *stack)
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

int	calculate_cost(t_stack *node, t_stack *a, t_stack *b)
{
	t_stack	*pair;
	int		rr;
	int		rrr;
	int		ra_rrb;
	int		rra_rb;

	pair = node->pair;
	if (node_pos(node->value, a) == 0)
		return (ft_min(pair->rot, pair->rev));
	else if (node_pos(pair->value, b) == 0)
		return (ft_min(node->rot, node->rev));
	rr = ft_max(node->rot, pair->rot);
	rrr = ft_max(node->rev, pair->rev);
	ra_rrb = node->rot + node->pair->rev;
	rra_rb = node->rev + node->pair->rot;
	return (ft_min(ft_min(rr, rrr), ft_min(ra_rrb, rra_rb)));
}

t_stack	*get_cheapest(t_stack *a, t_stack *b)
{
	t_stack	*node;
	t_stack	*cheapest;
	int		moves;

	get_moves(a);
	get_moves(b);
	node = a;
	cheapest = a;
	moves = calculate_cost(node, a, b);
	node = node->next;
	while (node)
	{
		if (calculate_cost(node, a, b) < moves)
		{
			moves = calculate_cost(node, a, b);
			cheapest = node;
		}
		node = node->next;
	}
	return (cheapest);
}
