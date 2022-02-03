# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/25 17:01:42 by aherrero          #+#    #+#              #
#    Updated: 2022/02/02 22:03:29 by aherrero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = client
NAME2 = server
NAME1_BONUS = client_bonus
NAME2_BONUS = server_bonus

SRC1 = client.c \
		utils.c

SRC2 = server.c \
		utils.c

OBJ = client.o \
		utils.o
OBJ_SERVER = server.o \
		utils.o

SRC1_BONUS = client_bonus.c \
		utils.c

SRC2_BONUS = server_bonus.c \
		utils.c

OBJ_BONUS = client_bonus.o \
		utils.o
OBJ_SERVER_BONUS = server_bonus.o \
		utils.o

GREEN = \033[1;32m
RED = \033[1;31m
YEL = \033[1;33m
WHT = \033[1;37m
EOC = \033[1;0m

HEADERS1 = includes/minitalk.h

CC = gcc

FLAGS = -Wall -Wextra -Werror -g -fsanitize=address

all: $(NAME1) $(NAME1_BONUS)

$(NAME1):		
		@echo "$(WHT)Compiling minitalk...$(EOC)"
		@$(CC) $(FLAGS) -c $(SRC1) -I$(HEADERS1)
		@$(CC) $(FLAGS) -o $(NAME1) $(OBJ) $(LIBFT) $(LIB)
		@$(CC) $(FLAGS) -c $(SRC2) -I$(HEADERS1)
		@$(CC) $(FLAGS) -o $(NAME2) $(OBJ_SERVER) $(LIBFT) $(LIB)
		@mkdir obj
		@mv $(OBJ) ./obj
		@mv server.o ./obj
		@echo "$(GREEN)minitalk build completed.$(EOC)"

bonus: $(NAME1_BONUS)

$(NAME1_BONUS):
		@echo "$(WHT)Compiling minitalk bonus...$(EOC)"
		@$(CC) $(FLAGS) -c $(SRC1_BONUS) -I$(HEADERS1)
		@$(CC) $(FLAGS) -o $(NAME1_BONUS) $(OBJ_BONUS) $(LIBFT) $(LIB)
		@$(CC) $(FLAGS) -c $(SRC2_BONUS) -I$(HEADERS1)
		@$(CC) $(FLAGS) -o $(NAME2_BONUS) $(OBJ_SERVER_BONUS) $(LIBFT) $(LIB)
		@mkdir obj_bonus
		@mv $(OBJ_BONUS) ./obj_bonus
		@mv server_bonus.o ./obj_bonus
		@echo "$(GREEN)minitalk bonus build completed.$(EOC)"

clean:
		@echo "$(WHT)Removing o-files...$(EOC)"
		@/bin/rm -f $(OBJ)
		@/bin/rm -f $(OBJ_BONUS)
		@/bin/rm -Rf obj
		@/bin/rm -Rf obj_bonus
		@echo "$(GREEN)Clean done.$(EOC)"

fclean: clean
		@echo "$(WHT)Removing object- and binary -files...$(EOC)"
		@/bin/rm -f $(NAME1) $(NAME2)
		@/bin/rm -f $(NAME1_BONUS) $(NAME2_BONUS)
		@echo "$(GREEN)fclean done.$(EOC)"

re: fclean all

.PHONY: all clean fclean re