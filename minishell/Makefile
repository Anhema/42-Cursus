# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 16:29:52 by aherrero          #+#    #+#              #
#    Updated: 2022/06/27 15:14:25 by aherrero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = minishell.c \
		main.c \
		env.c \
		env_aux.c \
		dict.c \
		dict_aux.c \
		echo.c \
		functions.c \
		functions_aux.c \
		functions_aux_two.c\
		functions_part_one.c \
		functions_part_two.c \
		ft_execve.c \
		signals.c \
		cd.c \
		fd.c \
		builtings.c \
		builtings_aux.c \
		redirections.c \
		redirections_syntax.c \
		redirections_aux.c \
		redirections_continue.c \
		expantions.c\
		readline.c\
		continue_execve.c\
		expand.c\
		expand_aux.c\
		free.c\
		aux_functions.c\

OBJ = $(SRC:.c=.o)

GREEN = \033[1;32m
RED = \033[1;31m
YEL = \033[1;33m
WHT = \033[1;37m
EOC = \033[1;0m

HEADERS = includes/minishell.h
LIBFT = libft/libft.a
CC = gcc -g3

READLINE_DIR = ${HOME}/.brew/opt/readline


FLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
F_READLINE = -I$(READLINE_DIR)/include
COMPILE = -lreadline -L$(READLINE_DIR)/lib

.c.o: $(SRC)
	@$(CC) $(FLAGS) $(F_READLINE) -c -o $@ $<


$(NAME):$(OBJ)
		@echo "$(WHT)Compiling libraries...$(EOC)"
		@${MAKE} -C libft
		@echo "$(GREEN)Libraries done.$(EOC)"
		@echo "$(WHT)Compiling Minishell...$(EOC)"
#		@$(CC) $(FLAGS) -c $(NAME) $(F_READLINE) $(SRC) $(LIBFT) 
		@$(CC) $(FLAGS) -o $(NAME) $(COMPILE) $(OBJ) $(LIBFT) 
		@echo "$(GREEN)Minishell build completed.$(EOC)"

all: $(NAME)

clean:
		@echo "$(WHT)Removing o-files...$(EOC)"
		@/bin/rm -f $(OBJ)
		@/bin/rm -f .history
		@${MAKE} -C libft clean
		@echo "$(GREEN)Clean done.$(EOC)"

fclean: clean
		@echo "$(WHT)Removing object- and binary -files...$(EOC)"
		@/bin/rm -f $(NAME)
		@${MAKE} -C libft fclean
		@echo "$(GREEN)fclean done.$(EOC)"

re: fclean all

.PHONY: all clean fclean re bonus