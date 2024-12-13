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

void	sort_2(t_stack **a, t_stack **b)
{
	if (!is_sorted())
	{
}

void	sort(t_stack **a, t_stack **b)
{
	t_stack	*node;
	t_stak	*tmp;

	if (is_sorted(*a) || *a == NULL)
		return ;
	if (get_nelems(*a) < 5)
	{
		if (get_nelemes(*a) == 2)
			sort_2(a, b);
		else
		{
			if (get_nelemes(*a) == 4)
				pb();
		}

	}
	else
	{
		sort_long(a, b);
	}
}
