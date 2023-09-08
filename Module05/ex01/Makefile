
NAME := Forms
SRC_DIR := srcs/
INC_DIR := ./includes/
INCLUDES := $(INC_DIR)Bureaucrat.hpp $(INC_DIR)Color.hpp $(INC_DIR)Form.hpp
SRCS := main.cpp Bureaucrat.cpp Form.cpp
SRCS := $(addprefix $(SRC_DIR),$(SRCS))
OBJS := $(SRCS:.cpp=.o)
CFLAGS := -Wall -Wextra -Werror -std=c++98 -I$(INC_DIR)
CC := c++

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Making" $(NAME)
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

%.o: $(SRC_DIR)/%.cpp $(INCLUDES)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning object files"
	@rm -f $(OBJS)

fclean: clean
	@echo "Cleaning" $(NAME)
	@rm -f $(NAME)

re: fclean all

.PHONY:
