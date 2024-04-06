NAME		=	webserv
NAME_SANI	=	$(addsuffix _sani, $(NAME))
CXX			=	c++ -g3
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98 -pedantic -Winvalid-pch
SANI_FLAG	=	-fsanitize=address
OBJDIR		=	objs/
OBJDIR_SANI	=	objs_sani/
PCHDIR		=	pch/
SRCS		=	$(wildcard srcs/*/*.cpp)
SRCDIRS		=	$(dir $(SRCS))
PCH_SRC 	=	$(wildcard srcs/*/*.hpp)
PCH_OUT 	=	$(addprefix $(PCHDIR), $(notdir $(PCH_SRC:.hpp=.gch)))
OBJS	 	=	$(addprefix $(OBJDIR), $(notdir $(SRCS:.cpp=.o)))
OBJS_SANI   = 	$(addprefix $(OBJDIR_SANI), $(SRCS:.cpp=_sani.o))
#CONFIG_SRC	=	$(wildcard srcs/Config/*.cpp)
#CONFIG_SRC  +=	$(wildcard srcs/Utilities/*.cpp)
#CONFIG_SRC  +=	$(wildcard srcs/Logger/*.cpp)
#CONFIG_SRC	+=	srcs/Core/main.cpp
#CONFIG_OBJS	=	$(addprefix $(OBJDIR), $(notdir $(CONFIG_SRC:.cpp=.o)))

INCFLAG		=	$(foreach header, $(PCH_OUT),-include $(header))
INCDIRS		=	$(foreach dir, $(dir $(PCH_SRC)), -I $(dir))

MKDIR		=	mkdir -p
RM			=	rm -fr
ECHO		=	echo

#.SILENT:

.SECONDARY: $(PCH_OUT)


all: $(NAME)

$(NAME):  $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCFLAG) $^ -o $(NAME)
	$(CXX) $(CXXFLAGS) $(SANI_FLAG) $(INCFLAG) $^ -o $(NAME_SANI)

$(OBJDIR)%.o: srcs/*/%.cpp $(PCH_SRC) | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -Winvalid-pch $(INCDIRS) -c $< -o $@
	$(CXX) $(CXXFLAGS) $(SANI_FLAG) -Winvalid-pch $(INCDIRS) -c $< -o $(@:.o=_sani.o)

$(PCHDIR):
	$(MKDIR) $(PCHDIR)

$(OBJDIR):
	$(MKDIR) $(OBJDIR)

test: all
	python3 tests/tester.py

sani: $(NAME_SANI)
	./$(NAME_SANI) default.conf

run: all
	./$(NAME) default.conf

re: fclean $(OBJDIR) all

clean:
	$(RM) $(OBJDIR)
	$(RM) $(PCHDIR)
	$(RM) $(OBJDIR_SANI)

const: all
	@$(ECHO) "n constructors ->"
	@./$(NAME) | grep "cons" | wc -l
	@$(ECHO) "n destructors ->"
	@./$(NAME) | grep "dest" | wc -l

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_SANI)


BLK		=	\e[0;30m
RED		=	\e[0;31m
GRN		=	\e[0;32m
YEL		=	\e[0;33m
BLU		=	\e[0;34m
MAG		=	\e[0;35m
CYN		=	\e[0;36m
WHT		=	\e[0;37m

B_BLK	=	\e[1;30m
B_RED	=	\e[1;31m
B_GRN	=	\e[1;32m
B_YEL	=	\e[1;33m
B_BLU	=	\e[1;34m
B_MAG	=	\e[1;35m
B_CYN	=	\e[1;36m
B_WHT	=	\e[1;37m
NC	=	\e[0m

.PHONY: all run clean fclean const sani
