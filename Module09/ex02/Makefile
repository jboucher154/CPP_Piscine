
NAME := PmergeMe
SRC_DIR := srcs/
INC_DIR := -I./includes
SRCS := main.cpp PmergeMe.cpp

SRCS := $(addprefix $(SRC_DIR),$(SRCS))
OBJS := $(SRCS:.cpp=.o)
CFLAGS := -Wall -Wextra -Werror -std=c++14 $(INC_DIR) -g
CC := c++

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Making" $(NAME)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp includes/PmergeMe.hpp
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning object files"
	@rm -f $(OBJS)

fclean: clean
	@echo "Cleaning" $(NAME)
	@rm -f $(NAME)

re: fclean all

help:
	@echo "Try making a list of integers for the program like this: "
	@echo "ARG=\"\$$(shuf -i 0-2147483647 -n 3000 | tr '\\\n' ' ')\"; ./PmergeMe \$$ARG"

.PHONY:
