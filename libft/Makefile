# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/19 14:32:42 by errero            #+#    #+#              #
#    Updated: 2022/04/19 17:25:17 by aherrero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_memset.c\
		ft_strlen.c\
		ft_strlcpy.c\
		ft_strcpy.c\
		ft_strncpy.c\
		ft_strlcat.c\
		ft_strncmp.c\
		ft_strcmp.c\
		ft_strchr.c\
		ft_strrchr.c\
		ft_strnstr.c\
		ft_strstr.c\
		ft_strdup.c\
		ft_isalpha.c\
		ft_isdigit.c\
		ft_isalnum.c\
		ft_isascii.c\
		ft_isprint.c\
		ft_toupper.c\
		ft_tolower.c\
		ft_memcpy.c\
		ft_memchr.c\
		ft_memccpy.c\
		ft_memmove.c\
		ft_memcmp.c\
		ft_bzero.c\
		ft_atoi.c\
		ft_calloc.c\
		ft_strjoin.c\
		ft_substr.c\
		ft_strtrim.c\
		ft_split.c\
		ft_itoa.c\
		ft_strmapi.c\
		ft_striteri.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
        ft_print_colors.c\
		ft_read_file.c\
		ft_str_equals.c\
		ft_strreplace.c\

BONUS = ft_lstnew.c\
          ft_lstadd_front.c\
          ft_lstsize.c\
          ft_lstlast.c\
          ft_lstadd_back.c\
          ft_lstdelone.c\
          ft_lstclear.c\
          ft_lstiter.c\
          ft_lstmap.c\

GREEN = \033[1;32m
RED = \033[1;31m
YEL = \033[1;33m
WHT = \033[1;37m
EOC = \033[1;0m

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS:.c=.o)

LIBC = ar rcs
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
INCS = libft.h

.c.o: $(SRC)
	@$(CC) $(FLAGS) -c -o $@ $<

all: $(NAME)

$(NAME):$(OBJS)
	@$(CC) $(CFLAGS) -c $(SRCS) -I$(INCS)
	@$(LIBC) $(NAME) $(OBJS)
	@mkdir obj
	@mv $(OBJS) ./obj

clean:
	@/bin/rm -f $(OBJS)
	@/bin/rm -Rf obj

fclean: clean
	@/bin/rm -f $(NAME) $(NAME2)

re: fclean all

bonus: $(BONUS_OBJS)
	$(LIBC) $(NAME) $(BONUS_OBJS)

.PHONY: all bonus clean fclean re
