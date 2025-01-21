GREEN=\033[0;32m
NC=\033[0m

NAME                = push_swap
BONUS               = checker

LIBFT               = ./libft/libft.a
INC                 = includes/
SRC_DIR             = srcs/
BONUS_DIR           = bonus/
OBJ_DIR             = obj/

CC                  = cc
CFLAGS              = -Wall -Werror -Wextra -I$(INC)
RM                  = rm -rf

SRCS				= $(SRC_DIR)operations/push.c \
					  $(SRC_DIR)operations/reverse_rotate.c \
					  $(SRC_DIR)operations/rotate.c \
					  $(SRC_DIR)operations/swap.c \
					  $(SRC_DIR)push_swap/push_swap_utils.c \
					  $(SRC_DIR)push_swap/sort_three.c \
					  $(SRC_DIR)push_swap/sort_five.c \
					  $(SRC_DIR)push_swap/sort_stack.c \
					  $(SRC_DIR)push_swap/stack_init.c \
					  $(SRC_DIR)push_swap/stack_utils.c

MAIN                = $(SRC_DIR)push_swap/push_swap.c
MAIN_OBJ            = $(addprefix $(OBJ_DIR), $(MAIN:.c=.o))

OBJS				= $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

BSRCS 				= $(BONUS_DIR)checker.c \
                      $(BONUS_DIR)get_next_line/get_next_line.c \
                      $(BONUS_DIR)get_next_line/get_next_line_utils.c

BONUS_OBJ 			= $(addprefix $(OBJ_DIR), $(BSRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS) $(MAIN_OBJ)
	@make -C ./libft
	@$(CC) $(OBJS) $(MAIN_OBJ) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)push_swap compiled$(NC)"

bonus: $(OBJS) $(BONUS_OBJ)
	@make -C ./libft
	@$(CC) $(OBJS) $(BONUS_OBJ) $(LIBFT) -o $(BONUS)
	@echo "$(GREEN)checker compiled$(NC)"

$(OBJ_DIR)%.o: %.c $(INC)push_swap.h
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C ./libft
	@$(RM) $(OBJS) $(BONUS_OBJ) $(MAIN_OBJ)
	@$(RM) $(OBJ_DIR)
	@echo "$(GREEN)Object files cleaned$(NC)"

fclean: clean
	@make fclean -C ./libft
	@$(RM) $(NAME) $(BONUS)
	@echo "$(GREEN)All cleaned$(NC)"

re: fclean all

.PHONY: re fclean clean all bonus
