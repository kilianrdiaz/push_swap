# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kroyo-di <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 18:32:05 by kroyo-di          #+#    #+#              #
#    Updated: 2024/12/04 18:32:14 by kroyo-di         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra

LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

HEADER = header/push_swap.h
SRC_DIR = sources/
SRC = push_swap.c get_stack.c print_error.c utils.c swap.c push.c rotate.c reverse.c \
	sort_3.c node_utils.c
SRCS = $(addprefix $(SRC_DIR), $(SRC))

OBJS = $(SRCS:.c=.o)

NAME = push_swap

# Regla principal
all: $(NAME)

# Compilar libft antes de compilar el proyecto principal
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

# Crear el ejecutable, enlazando correctamente libft
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(OBJS) -L$(LIBFT_DIR) -lft

# Regla para crear objetos a partir de los .c
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

# Limpiar objetos del proyecto y subproyecto libft
clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

# Limpiar todo, incluyendo libft.a y el ejecutable
fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

# Reconstruir todo
re: fclean all

.PHONY: all clean fclean re

