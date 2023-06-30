# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/29 16:37:09 by jebouche          #+#    #+#              #
#    Updated: 2023/06/29 16:37:12 by jebouche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
SRC = megaphone.cpp
CFLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) 

clean:
	@echo "Cleaning object files..."
	rm -f *.o

fclean: clean
	rm $(NAME)

.PHONY:
re: fclean all