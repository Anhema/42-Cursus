# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/19 14:32:42 by errero            #+#    #+#              #
#    Updated: 2022/01/05 14:40:24 by aherrero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libft.a

SRCS    = ft_memset.c\
          ft_strlen.c\
          ft_strlcpy.c\
          ft_strlcat.c\
          ft_strncmp.c\
          ft_strcmp.c\
          ft_strchr.c\
          ft_strrchr.c\
          ft_strnstr.c\
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

BONUS   = ft_lstnew.c\
          ft_lstadd_front.c\
          ft_lstsize.c\
          ft_lstlast.c\
          ft_lstadd_back.c\
          ft_lstdelone.c\
          ft_lstclear.c\
          ft_lstiter.c\
          ft_lstmap.c\

OBJS    = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS:.c=.o)

LIBC    = ar rcs
CC      = gcc
RM      = rm -f
CFLAGS  = -Wall -Wextra -Werror
INCS    = libft.h

all:    $(NAME)

$(NAME): $(OBJS) $(INCLUDE)
	$(LIBC) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(BONUS_OBJS)
	$(LIBC) $(NAME) $(BONUS_OBJS)

.PHONY: all bonus clean fclean re
