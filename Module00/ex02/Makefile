# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/03 13:50:47 by jebouche          #+#    #+#              #
#    Updated: 2023/07/03 15:06:43 by jebouche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Tests_Account_Class
INCLUDES = Account.hpp
SRC = Account.cpp tests.cpp
CFLAGS = -Wall -Wextra -Werror -std=c++98 -I.
CC = c++

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) 

clean:
	@echo "Cleaning object files..."
	rm -f *.o

fclean: clean
	rm $(NAME)

.PHONY:
re: fclean all
