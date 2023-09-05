
NAME := Polymorphism
INCLUDES := Animal.hpp Cat.hpp Dog.hpp WrongAnimal.hpp WrongCat.hpp
SRCS := main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp
OBJS := $(SRCS:.cpp=.o)
CFLAGS := -Wall -Wextra -Werror -std=c++98 -I.
SHADOW_FLAGS = -Wshadow -Wno-shadow
CC := c++

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Making Polymorphism"
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME) 

%.o: %.cpp $(INCLUDES)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning object files"
	@rm -f $(OBJS)

fclean: clean
	@echo "Cleaning Polymorphism"
	@rm -f $(NAME)

re: fclean all

.PHONY:
