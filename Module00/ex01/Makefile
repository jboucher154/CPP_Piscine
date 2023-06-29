NAME = my_awesome_phonebook
INCLUDES = Contact.hpp PhoneBook.hpp
SRC = main.cpp Contact.cpp Phonebook.cpp
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
