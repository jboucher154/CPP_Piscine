NAME := Aaaaand...OPEN
INCLUDES := ClapTrap.hpp
SRCS := main.cpp ClapTrap.cpp
OBJS := $(SRCS:.cpp=.o)
CFLAGS := -Wall -Wextra -Werror -std=c++98 -I.
CC := c++

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Creating Aaaaand...OPEN!"
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME) 

%.o: %.cpp $(INCLUDES)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning object files"
	@rm -f $(OBJS)

fclean: clean
	@echo "Cleaning Aaaaand...OPEN!"
	@rm $(NAME)

re: fclean all

.PHONY:
