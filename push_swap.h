#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"
# include "Libft/libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

void	print_error(void);
void	get_stack(int ac, char **av, t_stack **stack);
void	sa(t_stack **a);

int		get_nelems(t_stack *stack);

#endif	
