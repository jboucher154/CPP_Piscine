# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/05 15:45:37 by jebouche          #+#    #+#              #
#    Updated: 2023/07/05 16:57:13 by jebouche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := Hi_This_Is_Brain
SRC := main.cpp
OBJ := $(SRC:.cpp=.o)
CFLAGS := -Wall -Wextra -Werror -std=c++98
CC := c++

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) 

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning object files..."
	rm -f $(OBJ)

fclean: clean
	rm $(NAME)

.PHONY:
re: fclean all