/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:43:57 by jebouche          #+#    #+#             */
/*   Updated: 2023/06/30 15:11:08 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"

# define	FAILURE 1
# define	SUCCESS 0

class	PhoneBook 
{
	public:
		PhoneBook(void);
		~PhoneBook(void);
		int		userInterface(void);
		
	private: 
		Contact	_contacts[8];
		int		_contact_index;
		bool	_filled;
		
		int		_setContactInfo(void);
		int		_setFirstName(void);
		int		_setLastName(void);
		int		_setNickname(void);
		int		_setPhoneNumber(void);
		int		_setDarkestSecret(void);
		int		_getInput(std::string *read_to);
		void	_displaySummary(void);
		void	_printField(std::string to_print);
		void	_displaySearched(int searched);
		int		_addContact(void);
		int		_search(void);
};

#endif
