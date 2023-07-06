NAME := orthodoxCanonicalForm
INCLUDES := Fixed.hpp
SRCS := main.cpp Fixed.cpp
OBJS := $(SRCS:.cpp=.o)
CFLAGS := -Wall -Wextra -Werror -std=c++98 -I.
CC := c++

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Creating orthodoxCanonicalForm..."
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME) 

%.o: %.cpp $(INCLUDES)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning object files..."
	@rm -f $(OBJS)

fclean: clean
	@echo "Cleaning orthodoxCanonicalForm..."
	@rm $(NAME)

re: fclean all

.PHONY: