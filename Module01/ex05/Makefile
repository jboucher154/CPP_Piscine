# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/04 17:28:52 by jebouche          #+#    #+#              #
#    Updated: 2023/07/04 17:28:55 by jebouche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := Harl_2_0
INCLUDES := Harl.hpp
SRCS := main.cpp Harl.cpp
CFLAGS := -Wall -Wextra -Werror -std=c++98 -I.
CC := c++

all: $(NAME)

$(NAME): $(SRC) $(INCLUDES)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) 

clean:
	@echo "Cleaning object files..."
	rm -f *.o

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY: