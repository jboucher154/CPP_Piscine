# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/05 15:45:37 by jebouche          #+#    #+#              #
#    Updated: 2023/07/05 15:45:38 by jebouche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := Hi_This_Is_Brain
SRC := main.cpp
CFLAGS := -Wall -Wextra -Werror -std=c++98
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