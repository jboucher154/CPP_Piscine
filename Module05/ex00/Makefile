
NAME := Bureaucrat
SRC_DIR := srcs/
INC_DIR := -I./includes
# INCLUDES := $(INC_DIR)Bureaucrat.hpp $(INC_DIR)Color.hpp
SRCS := main.cpp Bureaucrat.cpp
SRCS_P := $(addprefix $(SRC_DIR),$(SRCS))
OBJS := $(SRCS_P:.cpp=.o)
CFLAGS := -Wall -Wextra -Werror -std=c++98 #$(INC_DIR)
CC := c++


all: $(NAME)

$(NAME): $(OBJS)
	@echo "Making Bureaucrat"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INC_DIR)

$(OBJS): %.o: %.cpp #$(INCLUDES)
	@$(CC) $(CFLAGS) $(INC_DIR) -c $< -o $@ 

clean:
	@echo "Cleaning object files"
	@rm -f $(OBJS)

fclean: clean
	@echo "Cleaning Bureaucrat"
	@rm -f $(NAME)

re: fclean all

.PHONY:
