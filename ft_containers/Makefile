# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/05 17:26:04 by aherrero          #+#    #+#              #
#    Updated: 2022/12/30 13:31:14 by aherrero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_containers

SRC =  main.cpp\
#		vector.cpp\

OBJ = $(SRC:.cpp=.o)

LIB = ft_containers.hpp\
		Vector.hpp\

INCLUDES = $(addprefix  -I, $(LIB))

GREEN = \033[1;32m
RED = \033[1;31m
YEL = \033[1;33m
WHT = \033[1;37m
EOC = \033[1;0m

CC = clang++ $(INCLUDES) -Wpedantic -pedantic-errors -g3 -std=c++98
FLAGS =  -Wunused-value -Wall -Wextra -Werror -fsanitize=address

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