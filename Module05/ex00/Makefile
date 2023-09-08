
NAME := Bureaucrat
SRC_DIR := srcs/
INC_DIR := ./includes/
INCLUDES := $(INC_DIR)Bureaucrat.hpp $(INC_DIR)Color.hpp
SRCS := main.cpp Bureaucrat.cpp
SRCS := $(addprefix $(SRC_DIR),$(SRCS))
OBJS := $(SRCS:.cpp=.o)
CFLAGS := -Wall -Wextra -Werror -std=c++98 -I$(INC_DIR)
CC := c++

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Making Bureaucrat"
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

%.o: $(SRC_DIR)/%.cpp $(INCLUDES)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning object files"
	@rm -f $(OBJS)

fclean: clean
	@echo "Cleaning Bureaucrat"
	@rm -f $(NAME)

re: fclean all

.PHONY:
