NAME	=	push_swap
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g3

HEAD	=	includes/push_swap.h
SRC_DIR =	src/
OBJ_DIR =	objs/

SRC_FILES	=	push_swap_utils.c \
				push_swap.c \
				rotate.c \
				revers_rotate.c \
				push.c	\
				swap.c \
				stack.c	\
				checker.c	\
				sorter.c	\
				finder.c

OBJS	=	$(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

LIBFT_DIR	=	libft/

all:	lib $(NAME)

lib:
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "Libft Compiled"

$(NAME): $(OBJ_DIR) $(OBJS) $(HEAD)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) libft/libft.a

$(OBJ_DIR)%.o: $(SRC_DIR)%.c libft/libft.h libft/libft.a | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) clean --silent -C  $(LIBFT_DIR)

fclean: clean
	@echo "Clean all binary"
	@rm -f $(NAME)
	@rm -f libft/libft.a

re: fclean all

.PHONY: all clean fclean re
