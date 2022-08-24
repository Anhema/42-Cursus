# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/11 17:18:06 by aherrero          #+#    #+#              #
#    Updated: 2022/08/14 22:16:28 by cbustama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

detected_OS := $(shell sh -c 'uname 2>/dev/null || echo Unknown')

NAME = cub3D

NAME_BONUS = cub3D_bonus

FILES = mandatory/cub3d \
		mandatory/game_manager \
		mandatory/data/get_map \
		mandatory/data/fill_map\
        mandatory/data/get_player\
		mandatory/data/free_map\
		mandatory/raycasting/raycasting\
		mandatory/raycasting/draw_map\
		mandatory/raycasting/draw_texture\
		mandatory/raycasting/draw_terminal\
		mandatory/moves/cam_movements\
		mandatory/moves/get_movements\
		mandatory/validation/continue_map_checker\
		mandatory/validation/header_validation\
		mandatory/validation/header_validation_aux\
		mandatory/validation/header_validation_aux_2\
		mandatory/validation/map_validation\
		mandatory/validation/map_checker\
		mandatory/validation/map_validation_header\

FILES_BONUS = bonus/cub3d_bonus \
			  bonus/game_manager_bonus \
			  bonus/data/get_map_bonus \
			  bonus/data/get_map_bonus_ext \
			  bonus/data/fill_map_bonus\
			  bonus/data/get_player_bonus\
			  bonus/data/free_map_bonus\
			  bonus/raycasting/raycasting_bonus\
			  bonus/raycasting/raycasting_bonus_ext\
			  bonus/raycasting/draw_map_bonus\
			  bonus/raycasting/colors_bonus\
			  bonus/raycasting/sprites_bonus\
			  bonus/raycasting/draw_texture_bonus\
			  bonus/raycasting/draw_terminal_bonus\
			  bonus/raycasting/sky_floor_raycasting_bonus\
			  bonus/moves/cam_movements_bonus\
			  bonus/moves/get_movements_bonus\
			  bonus/moves/get_movements_bonus_ext\
			  bonus/validation/continue_map_checker_bonus\
			  bonus/validation/header_validation_bonus\
			  bonus/validation/header_validation_aux_bonus\
			  bonus/validation/header_validation_aux_2_bonus\
			  bonus/validation/map_validation_bonus\
			  bonus/validation/map_checker_bonus\
			  bonus/validation/map_validation_header_bonus\

SRC = $(addsuffix .c, $(FILES))
OBJ = $(addsuffix .o, $(FILES))

SRC_BONUS = $(addsuffix .c, $(FILES_BONUS))
BONUS_OBJS = $(addsuffix .o, $(FILES_BONUS))

GREEN = \033[1;32m
RED = \033[1;31m
YEL = \033[1;33m
WHT = \033[1;37m
EOC = \033[1;0m

HEADERS = -I $(CURDIR)/mandatory/includes
HEADERS_BONUS = -I $(CURDIR)/bonus/includes
LIBFT = libft/libft.a

CC = gcc -g3
FLAGS = -Wall -Wextra -Werror -Imlx #-fsanitize=address

.c.o: $(SRC) $(SRC_BONUS)
	@$(CC) $(FLAGS) $(HEADERS) $(HEADERS_BONUS) -c -o $@ $<

$(NAME): $(OBJ) $(LIBFT)
ifeq ($(detected_OS),Darwin)
		@${MAKE} -C mlx 2>.errors
		@$(CC) $(FLAGS) $(HEADERS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJ) $(LIBFT)
else
		@${MAKE} -C minilibx 2>.errors
		@$(CC) $(FLAGS) -lmlx -lm -lbsd -lX11 -lXext -o $(NAME) $(OBJ) $(LIBFT)

endif
#		@mkdir -p mandatory/obj/
#		@mv $(OBJ) ./mandatory/obj/

$(LIBFT):
		@echo "$(WHT)Compiling libraries...$(EOC)"
		@${MAKE} -C libft
		@echo "$(GREEN)cub3D build completed.$(EOC)"

all: $(NAME) $(NAME_BONUS)

bonus: $(NAME_BONUS) $(LIBFT)

$(NAME_BONUS): $(BONUS_OBJS) $(LIBFT)

ifeq ($(detected_OS),Darwin)
		@${MAKE} -C mlx 2>.errors
		@$(CC) $(FLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS) $(BONUS_OBJS) $(LIBFT)
else
		@${MAKE} -C mlx 2>.errors
		@$(CC) $(FLAGS) -lmlx -lm -lbsd -lX11 -lXext -o $(NAME_BONUS) $(BONUS_OBJS) $(LIBFT)

endif
#		@mkdir -p bonus/obj_bonus
#		@mv $(BONUS_OBJS) ./bonus/obj_bonus

clean:
		@echo "$(WHT)Removing o-files...$(EOC)"
		@/bin/rm -f $(OBJ)
		@/bin/rm -f $(BONUS_OBJS)
		@/bin/rm -Rf mandatory/obj
		@/bin/rm -Rf bonus/obj_bonus
		@/bin/rm -f .errors
		@/bin/rm -Rf obj_bonus
		@echo "$(GREEN)Clean done.$(EOC)"

fclean: clean
		@echo "$(WHT)Removing object- and binary -files...$(EOC)"
		@/bin/rm -f $(NAME)
		@/bin/rm -f $(NAME_BONUS)
		@${MAKE} -C libft fclean
		@${MAKE} -C mlx clean
		@echo "$(GREEN)fclean done.$(EOC)"

re: fclean all

.PHONY: all clean fclean re bonus