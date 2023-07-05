# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/05 15:43:45 by jebouche          #+#    #+#              #
#    Updated: 2023/07/05 15:43:46 by jebouche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := sed_is_for_losers
SRC := main.cpp
CFLAGS := -Wall -Wextra -Werror -std=c++98
CC := c++

all: $(NAME)

$(NAME): $(SRC) $(INCLUDES)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

run_test: $(NAME)
	@echo "Testing..."
	@bash tests.sh

remove_tests:
	@echo "Removing test files..."
	@rm -f test_file0.txt.replace test_file1.txt.replace whiskers.txt.replace

clean:
	@echo "Cleaning object files..."
	rm -f *.o

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY:
