/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroyo-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:42:46 by kroyo-di          #+#    #+#             */
/*   Updated: 2024/11/22 17:42:48 by kroyo-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args(char **args)
{
	int	i;
	int	j;

	i = 1;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if (!ft_isdigit(args[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

t_stack	*create_node(int value, t_stack *last_node)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	node->value = value;
	node->next = last_node;
	return (node);
}

void	get_stack(int ac, char **av, t_stack **stack)
{
	int 	i;
	int		num;
	t_stack *last_node;
	
	i = ac;
	if (!check_args(av))
		print_error();
	last_node = NULL;
	while (--i)
	{
		num = ft_atoi(av[i]);
		*stack = create_node(num, last_node);
		last_node = *stack;
	}
}
