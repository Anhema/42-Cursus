# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 19:43:47 by aherrero          #+#    #+#              #
#    Updated: 2022/04/01 17:05:43 by aherrero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

SRC = philo_bonus.c \
		errors_bonus.c \
		utils_bonus.c \
		philo_utils_bonus.c \
		philo_create_bonus.c \
		philo_status_bonus.c \
		philo_forks_bonus.c \

OBJ = $(SRC:.c=.o)

GREEN = \033[1;32m
RED = \033[1;31m
YEL = \033[1;33m
WHT = \033[1;37m
EOC = \033[1;0m

HEADERS = includes/philo_bonus.h
CC = gcc

FLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address

.c.o: $(SRC)
	@$(CC) $(FLAGS) -c -o $@ $<


$(NAME):$(OBJ)

		@echo "$(WHT)Compiling Philosophers...$(EOC)"
		@$(CC) $(FLAGS) -o $(NAME) $(OBJ)
		@echo "$(GREEN)Philosophers build completed.$(EOC)"

all: $(NAME)

bonus: $(NAME)

clean:
		@echo "$(WHT)Removing o-files...$(EOC)"
		@/bin/rm -f $(OBJ)
		@echo "$(GREEN)Clean done.$(EOC)"

fclean: clean
		@echo "$(WHT)Removing object- and binary -files...$(EOC)"
		@/bin/rm -f $(NAME)
		@echo "$(GREEN)fclean done.$(EOC)"

re: fclean all

.PHONY: all clean fclean re bonus
