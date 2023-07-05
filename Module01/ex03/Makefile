# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/05 15:46:08 by jebouche          #+#    #+#              #
#    Updated: 2023/07/05 15:46:12 by jebouche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := Unnecessary_violence
INCLUDES := Weapon.hpp HumanA.hpp HumanB.hpp
SRC := main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
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