NAME := Repetative_Work
INCLUDES := ClapTrap.hpp ScavTrap.hpp FragTrap.hpp
SRCS := main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
OBJS := $(SRCS:.cpp=.o)
CFLAGS := -Wall -Wextra -Werror -std=c++98 -I.
CC := c++

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Repetative_Work"
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME) 

%.o: %.cpp $(INCLUDES)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning object files"
	@rm -f $(OBJS)

fclean: clean
	@echo "Cleaning Repetative_Work"
	@rm -f $(NAME)

re: fclean all

.PHONY:
