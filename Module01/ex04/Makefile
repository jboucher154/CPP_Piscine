# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jebouche <jebouche@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/05 15:43:45 by jebouche          #+#    #+#              #
#    Updated: 2023/08/06 14:27:32 by jebouche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := sed_is_for_losers
SRC := main.cpp
OBJ := $(SRC:.cpp=.o)
CFLAGS := -Wall -Wextra -Werror -std=c++98 -g
CC := c++

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

%.o: %.cpp $(INCLUDES)
	@$(CC) $(CFLAGS) -c $< -o $@

run_test: $(NAME)
	@echo "Testing..."
	@bash tests.sh

remove_tests:
	@echo "Removing test files..."
	@rm -f test_file0.txt.replace test_file1.txt.replace whiskers.txt.replace nope_file.txt

clean:
	@echo "Cleaning object files..."
	rm -f $(OBJ)

fclean: clean
	@echo "Cleaning sed_is_for_losers..."
	rm $(NAME)

re: fclean all

.PHONY:
