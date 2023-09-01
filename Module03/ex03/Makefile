NAME := Now_its_weird
INCLUDES := ClapTrap.hpp ScavTrap.hpp FragTrap.hpp DiamondTrap.hpp
SRCS := main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
OBJS := $(SRCS:.cpp=.o)
CFLAGS := -Wall -Wextra -Werror -std=c++98 -I.
SHADOW_FLAGS = -Wshadow -Wno-shadow
CC := c++

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Making Now_its_weird"
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME) 

%.o: %.cpp $(INCLUDES)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning object files"
	@rm -f $(OBJS)

fclean: clean
	@echo "Cleaning Now_its_weird"
	@rm -f $(NAME)

re: fclean all

.PHONY:
