# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 17:52:33 by aherrero          #+#    #+#              #
#    Updated: 2022/04/08 16:34:45 by aherrero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = philo.c \
		philo_forks.c \
		philo_utils.c \
		errors.c \
		philo_status.c \
		philo_one.c \
		utils.c \

OBJ = $(SRC:.c=.o)

GREEN = \033[1;32m
RED = \033[1;31m
YEL = \033[1;33m
WHT = \033[1;37m
EOC = \033[1;0m

HEADERS = includes/philo.h
CC = gcc

FLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address

.c.o: $(SRC)
	@$(CC) $(FLAGS) -c -o $@ $<


$(NAME):$(OBJ)

		@echo "$(WHT)Compiling Philosophers...$(EOC)"
		@$(CC) $(FLAGS) -o $(NAME) $(OBJ)
#		@mkdir obj
#		@mv $(OBJ) ./obj
		@echo "$(GREEN)Philosophers build completed.$(EOC)"

all: $(NAME)

clean:
		@echo "$(WHT)Removing o-files...$(EOC)"
		@/bin/rm -f $(OBJ)
#		@/bin/rm -Rf obj
		@echo "$(GREEN)Clean done.$(EOC)"

fclean: clean
		@echo "$(WHT)Removing object- and binary -files...$(EOC)"
		@/bin/rm -f $(NAME)
		@echo "$(GREEN)fclean done.$(EOC)"

re: fclean all

.PHONY: all clean fclean re bonus
