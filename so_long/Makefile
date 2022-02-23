# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/03 16:27:59 by aherrero          #+#    #+#              #
#    Updated: 2022/02/22 16:46:20 by aherrero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

NAME_BONUS = so_long_bonus

SRC = so_long.c \
	map_validator.c \
	map_validator_utils.c \
	map_renderer.c \
	player_movement.c \
	draw_walls.c \
	draw_walls_aux.c \
	get_imgs.c \
	delete_imgs.c \
	game_manager.c \

SRC_BONUS = so_long_bonus.c \
	map_validator_bonus.c \
	map_validator_utils_bonus.c \
	map_renderer_bonus.c \
	player_movement_bonus.c \
	enemy_movement_bonus.c \
	draw_walls_bonus.c \
	draw_walls_aux_bonus.c \
	get_imgs_bonus.c \
	get_imgs_aux_bonus.c \
	delete_imgs_bonus.c \
	game_manager_bonus.c \
	game_manager_aux_bonus.c \

OBJ = $(SRC:.c=.o)

BONUS_OBJS = $(SRC_BONUS:.c=.o)

GREEN = \033[1;32m
RED = \033[1;31m
YEL = \033[1;33m
WHT = \033[1;37m
EOC = \033[1;0m

HEADERS = includes/so_long.h
HEADERS_BONUS = includes/so_long_bonus.h
LIBFT = libft/libft.a
CC = gcc

FLAGS = -Wall -Wextra -Werror -Imlx #-g -fsanitize=address


$(NAME):
		@echo "$(WHT)Compiling libraries...$(EOC)"
		@${MAKE} -C libft
		@${MAKE} -C mlx 2>.errors
		@echo "$(GREEN)Libraries done.$(EOC)"
		@echo "$(WHT)Compiling so_long...$(EOC)"
		@$(CC) $(FLAGS) -c $(SRC) -I$(HEADERS)
		@$(CC) $(FLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJ) $(LIBFT)
		@mkdir obj
		@mv $(OBJ) ./obj
		@echo "$(GREEN)so_long build completed.$(EOC)"

all: $(NAME) $(NAME_BONUS)

bonus: $(NAME_BONUS)

$(NAME_BONUS):
		@echo "$(WHT)Compiling libraries...$(EOC)"
		@${MAKE} -C libft
		@${MAKE} -C mlx 2>.errors
		@echo "$(GREEN)Libraries done.$(EOC)"
		@echo "$(WHT)Compiling so_long bonus...$(EOC)"
		@$(CC) $(FLAGS) -c $(SRC_BONUS) -I$(HEADERS_BONUS)
		@$(CC) $(FLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS) $(BONUS_OBJS) $(LIBFT)
		@mkdir obj_bonus
		@mv $(BONUS_OBJS) ./obj_bonus
		@echo "$(GREEN)so_long bonus build completed.$(EOC)"

clean:
		@echo "$(WHT)Removing o-files...$(EOC)"
		@/bin/rm -f $(OBJ)
		@/bin/rm -f $(OBJ_BONUS)
		@/bin/rm -Rf obj
		@/bin/rm .errors
		@/bin/rm -Rf obj_bonus
		@${MAKE} -C libft clean
		@${MAKE} -C mlx clean
		@echo "$(GREEN)Clean done.$(EOC)"

fclean: clean
		@echo "$(WHT)Removing object- and binary -files...$(EOC)"
		@/bin/rm -f $(NAME)
		@/bin/rm -f $(NAME_BONUS)
		@${MAKE} -C libft fclean
		@${MAKE} -C mlx clean
		@echo "$(GREEN)fclean done.$(EOC)"

re: fclean all bonus

.PHONY: all clean fclean re bonus