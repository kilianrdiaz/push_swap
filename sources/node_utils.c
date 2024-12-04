/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroyo-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:51:28 by kroyo-di          #+#    #+#             */
/*   Updated: 2024/12/04 17:51:40 by kroyo-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_stack	*create_node(int value, t_stack *last_node)
{
	t_stack *node;

	node = (t_stack *)malloc(sizeof(t_stack));
	node->value = value;
	node->next = last_node;
	return (node);
}

void    delete_node(t_stack **node)
{
	t_stack *temp;

	temp = *node;
	*node = (*node)->next;
	free(temp);
}
