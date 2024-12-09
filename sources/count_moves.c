/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroyo-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:23:51 by kroyo-di          #+#    #+#             */
/*   Updated: 2024/12/09 21:57:50 by kroyo-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../header/push_swap.h"

int	is_upperhalf(t_stack *node, t_stack *stack)
{
	int	nelems;

	nelems = get_nelems(stack);
	if ((nelems / 2) >= get_node_pos(node->value, stack))
		return (1);
	else
		return (0);
}

int	moves_to_top(t_stack *node, t_stack *stack)
{
	int	nelems;

	nelems = get_nelems(stack);
	if (is_upperhalf(node))
		return (get_node_pos(node->value, stack));
	else
		return (get_nelems(stack) - get_node_pos(node->value, stack));
}

int	count_moves(t_stack *stack_a, t_stack *stack_b, t_stack *node)
{
	int		moves;
	int		count_a;
	int		count_b;

	count_a = moves_to_top(node, stack_a);
	count_b = moves_to_top(node->pair, stack_b);
	moves = 0;
	//rr
	if (is_upperhalf(node) && is_upperhalf(node->pair))
	{
		moves = count_a - count_b;
		if (moves < 0)
			return (count_a + moves + 1);
		else if (moves > 0)
			return (count_b + moves + 1);
	}
	//rrr
	else if(!is_upperhalf(node) && !is_upperhalf(node->pair))
	//ra + rrb
	else if(is_upperhalf(node))
	//rra + rb
	else

	return (moves);
}

t_stack	*get_cheapest(t_stack *a, t_stack *b)
{
	t_stack	*node;
	t_stack	*cheapest;
	int		moves;

	node = a;
	moves = count_moves(a, b, node);
	node = node->next;
	cheapest = NULL;
	while (node)
	{
		if (count_moves(a, b, node) < moves)
		{
			moves = count_moves(a, b, node);
			cheapest = node;
		}
		node = node->next;
	}
	return (cheapest);
}
