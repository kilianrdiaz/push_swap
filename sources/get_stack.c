/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroyo-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:42:46 by kroyo-di          #+#    #+#             */
/*   Updated: 2024/12/07 21:26:37 by kroyo-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

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
			if (!ft_isdigit(args[i][j]) && args[i][j] != '-')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_duplicates(char **args)
{
	int		i;
	int		j;
	char	*temp;

	i = 1;
	temp = args[i];
	while (temp)
	{
		j = i + 1;
		while (args[j])
		{
			if (ft_strcmp(temp, args[j]) == 0)
				return (0);
			j++;
		}
		temp = args[++i];
	}
	return (1);
}

void	get_stack(int ac, char **av, t_stack **stack)
{
	int		i;
	int		num;
	t_stack	*last_node;

	i = ac;
	if (!check_args(av) || !check_duplicates(av))
		print_error();
	last_node = NULL;
	while (--i)
	{
		num = ft_atoi(av[i]);
		*stack = create_node(num, last_node);
		last_node = *stack;
	}
}
