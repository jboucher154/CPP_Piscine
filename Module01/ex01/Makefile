# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/05 15:44:53 by jebouche          #+#    #+#              #
#    Updated: 2023/07/05 16:55:35 by jebouche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := Moar_Braiz
INCLUDES := Zombie.hpp
SRC := main.cpp Zombie.cpp zombieHorde.cpp
OBJ := $(SRC:.cpp=.o)
CFLAGS := -Wall -Wextra -Werror -std=c++98 -I.
CC := c++

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(INCLUDES)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning object files..."
	rm -f $(OBJ)

fclean: clean
	rm $(NAME)

.PHONY:
re: fclean all