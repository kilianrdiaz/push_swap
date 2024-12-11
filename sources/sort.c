/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroyo-di <kroyo-di@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:43:31 by kroyo-di          #+#    #+#             */
/*   Updated: 2024/12/10 19:57:55 by kroyo-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	sort(t_stack **a, t_stack **b)
{
	t_stack	*node;
	t_stak	*tmp;

	pb(a, b);
	pb(a, b);
	node = NULL;
	tmp = *a;
	while (get_nelems(*a) > 3)
	{
		node = get_cheapest(a, b);
		pairs_on_top(a, b, node);
	}
	sort_3(a);
}

