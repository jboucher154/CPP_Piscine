NAME = Tests_Account_Class
INCLUDES = Account.hpp
SRC = Account.hpp tests.cpp
CFLAGS = -Wall -Wextra -Werror -std=c++98 -I.
CC = c++

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) 

clean:
	@echo "Cleaning object files..."
	rm -f *.o

fclean: clean
	rm $(NAME)

.PHONY:
re: fclean all
