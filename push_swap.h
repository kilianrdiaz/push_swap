#ifndef PUSH_SWAP.H
# define PUSH_SWAP.H

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

#endif	
