# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/11 19:13:20 by aherrero          #+#    #+#              #
#    Updated: 2022/11/11 19:17:47 by aherrero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cast 

SRC =  main.cpp\

OBJ = $(SRC:.cpp=.o)

LIB = Data.hpp

INCLUDES = $(addprefix  -I, $(LIB))

GREEN = \033[1;32m
RED = \033[1;31m
YEL = \033[1;33m
WHT = \033[1;37m
EOC = \033[1;0m

CC = clang++ $(INCLUDES) -g3 -Wpedantic -pedantic-errors -Wunused-value
FLAGS = -std=c++98 -Wall -Wextra -Werror #-fsanitize=address

#.SILENT:

.cpp.o: $(SRC)
	@$(CC) $(FLAGS) -c -o $@ $<

$(NAME): $(OBJ)
		@$(CC) $(FLAGS) -o $(NAME) $(OBJ)

all: $(NAME)

clean:
		@echo "$(WHT)Removing o-files...$(EOC)"
		@/bin/rm -f $(OBJ)
		@/bin/rm -f *.d
		@echo "$(GREEN)Clean done.$(EOC)"

fclean: clean
		@echo "$(WHT)Removing object- and binary -files...$(EOC)"
		@/bin/rm -f $(NAME)
		@echo "$(GREEN)fclean done.$(EOC)"

re: fclean all

.PHONY: all clean fclean re bonus