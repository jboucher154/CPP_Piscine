NAME := Serena_my_love
INCLUDES := ClapTrap.hpp ScavTrap.hpp
SRCS := main.cpp ClapTrap.cpp ScavTrap.cpp
OBJS := $(SRCS:.cpp=.o)
CFLAGS := -Wall -Wextra -Werror -std=c++98 -I.
CC := c++

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Creating Serena_my_love!"
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME) 

%.o: %.cpp $(INCLUDES)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning object files"
	@rm -f $(OBJS)

fclean: clean
	@echo "Cleaning Serena_my_love"
	@rm -f $(NAME)

re: fclean all

.PHONY:
