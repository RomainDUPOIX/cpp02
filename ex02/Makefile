# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdupoix <rdupoix@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/19 14:32:20 by ehuet             #+#    #+#              #
#    Updated: 2026/08/31 13:16:16 by rdupoix          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ex02
CPP			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98 -g

# **************************************************************************** #

SRCS		=	main.cpp \
				Fixed.cpp

OBJS_DIR	= objs
OBJS		= $(SRCS:%.cpp=$(OBJS_DIR)/%.o)

HEADERS		=	Fixed.hpp \

# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o: %.cpp $(HEADERS)
	@mkdir -p $(OBJS_DIR)
	$(CPP) $(CFLAGS) -c $< -o $@

run: re
	./$(NAME)
	
debug: re
	gdb -tui ./$(NAME)

vg: re
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes ./$(NAME)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

# **************************************************************************** #