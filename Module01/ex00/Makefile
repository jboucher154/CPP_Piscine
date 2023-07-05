# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/05 15:44:04 by jebouche          #+#    #+#              #
#    Updated: 2023/07/05 15:44:05 by jebouche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := BraiiiiiiinnnzzzZ
INCLUDES := Zombie.hpp
SRC := main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
CFLAGS := -Wall -Wextra -Werror -std=c++98 -I.
CC := c++

all: $(NAME)

$(NAME): $(SRC) $(INCLUDES)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) 

clean:
	@echo "Cleaning object files..."
	rm -f *.o

fclean: clean
	rm $(NAME)

.PHONY:
re: fclean all