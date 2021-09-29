# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aherrero <aherrero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/08 18:26:26 by aherrero          #+#    #+#              #
#    Updated: 2021/09/27 17:30:10 by aherrero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

SRC=$(wildcard ./*.c)

OBJ=$(patsubst ./%.c, ./%.o, $(SRC))

LIBFT=libft

CC=gcc

CFLAGS=-Wall -Wextra -Werror

RM=rm -f

$(NAME): $(OBJ)
		@make -C $(LIBFT)
		@cp libft/libft.a ./$(NAME)
		@ar -rcs $(NAME) $(OBJ)
		@mkdir obj
		@mv $(OBJ) ./obj
		@rm -f $(OBJ)
		@rm -Rf obj

all: $(NAME)

clean:
		@$(RM) $(OBJ)
		@make clean -C $(LIBFT)

fclean: clean
		@${RM} libftprintf.a
		@make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re .c .o