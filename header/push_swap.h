/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroyo-di <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:42:38 by kroyo-di          #+#    #+#             */
/*   Updated: 2024/12/04 18:39:49 by kroyo-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../Libft/libft.h"
# include "../Libft/ft_printf/ft_printf.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

void	print_error(void);
void	get_stack(int ac, char **av, t_stack **stack);
void	delete_node(t_stack **node);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void    ra(t_stack **a);
void    rb(t_stack **b);
void    rr(t_stack **a, t_stack **b);
void    rra(t_stack **a);
void    rrb(t_stack **b);
void    rrr(t_stack **a, t_stack **b);
void	sort_3(t_stack **stack);

int		get_nelems(t_stack *stack);
int		get_min(t_stack *stack);
int		get_max(t_stack *stack);
int		check_sorted(t_stack *stack);

t_stack	*create_node(int value, t_stack *last_node);

//ELIMINAR ANTES DE ENTREGAR
void	print_stack(t_stack *stack_a, t_stack *stack_b);

#endif	