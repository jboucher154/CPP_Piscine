
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"

# define	FAILURE 1
# define	SUCCESS 0

class	PhoneBook 
{
	private: 
		Contact	contacts[8];
		int		contact_index;
		bool	filled;
		int		_set_contact_info(void);
		int		_set_first_name(void);
		int		_set_last_name(void);
		int		_set_nickname(void);
		int		_set_phone_number(void);
		int		_set_darkest_secret(void);
		int		_get_input(std::string *read_to);
		void	_display_summary(void);
		void	_print_field(std::string to_print);
		void	_display_searched(int searched);
		int		_add_contact(void);
		int		_search(void);
	public:
		PhoneBook(void);
		~PhoneBook(void);
		int		ui(void);
};

#endif