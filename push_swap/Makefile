# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/05 13:52:59 by aherrero          #+#    #+#              #
#    Updated: 2022/01/13 19:45:00 by aherrero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = push_swap

SRC1 = push_swap.c \
		sort.c \
		sort_two.c \
		sort_three.c \
		sort_five.c \
		sort_only_five.c \
		sort_only_ten.c \
		sort_ten.c \
		check_control.c \
		check_errors.c \
		chunk_utils.c \
		stack_utils.c \
		operations.c

OBJ = *.o

GREEN = \033[1;32m
RED = \033[1;31m
YEL = \033[1;33m
WHT = \033[1;37m
EOC = \033[1;0m

HEADERS1 = includes/push_swap.h

LIBFT = libft/libft.a
CC = gcc

FLAGS = -Wall -Wextra -Werror -g -fsanitize=address

all: $(NAME1)

$(NAME1):
	@echo "$(WHT)Compiling libraries...$(EOC)"
	@${MAKE} -C libft
	@echo "$(GREEN)Libraries done.$(EOC)"

	@echo "$(WHT)Compiling push_swap...$(EOC)"
	@$(CC) $(FLAGS) -c $(SRC1) -I$(HEADERS1)
	@$(CC) $(FLAGS) -o $(NAME1) $(OBJ) $(LIBFT) $(LIB)
	@mkdir obj
	@mv $(OBJ) ./obj
	@echo "$(GREEN)push_swap build completed.$(EOC)"
	
clean:
	@echo "$(WHT)Removing o-files...$(EOC)"
	@/bin/rm -f $(OBJ)
	@/bin/rm -Rf obj
	@${MAKE} -C libft clean
	@echo "$(GREEN)Clean done.$(EOC)"

fclean: clean
	@echo "$(WHT)Removing object- and binary -files...$(EOC)"
	@/bin/rm -f $(NAME1) $(NAME2)
	@${MAKE} -C libft fclean
	@echo "$(GREEN)fclean done.$(EOC)"

re: fclean all

.PHONY: all clean fclean re