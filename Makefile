CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF_DIR = ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
SRC = push_swap.c get_stack.c print_error.c utils.c swap.c
OBJ = $(SRC:.c=.o)
NAME = push_swap

all: $(LIBFT) $(FT_PRINTF) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	@$(MAKE) -C $(FT_PRINTF_DIR)

$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(MAKE) clean -C $(FT_PRINTF_DIR)
	rm -f $(OBJ)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(MAKE) fclean -C $(FT_PRINTF_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
