
NAME := Interns
SRC_DIR := srcs/
INC_DIR := -I./includes
SRCS := main.cpp \
		Bureaucrat.cpp \
		AForm.cpp \
		PresidentialPardonForm.cpp \
		ShrubberyCreationForm.cpp \
		RobotomyRequestForm.cpp \
		Intern.cpp \

SRCS := $(addprefix $(SRC_DIR),$(SRCS))
OBJS := $(SRCS:.cpp=.o)
CFLAGS := -Wall -Wextra -Werror -std=c++98 $(INC_DIR)
CC := c++

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Making" $(NAME)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning object files"
	@rm -f $(OBJS)

fclean: clean
	@echo "Cleaning" $(NAME)
	@rm -f $(NAME)

re: fclean all

.PHONY:
