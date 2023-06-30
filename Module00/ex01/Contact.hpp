/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:40:10 by jebouche          #+#    #+#             */
/*   Updated: 2023/06/29 17:42:14 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class	Contact 
{
	public:
		Contact(void);
		~Contact(void);
		void		setFirstName(std::string fname);
		void		setLastName(std::string lname);
		void		setNickname(std::string nname);
		void		setPhoneNumber(std::string pnumber);
		void		setDarkestSecret(std::string secret);
		std::string	getFirstName(void) const;
		std::string	getLastName(void) const;
		std::string	getNickname(void) const;
		std::string	getPhoneNumber(void) const;
		std::string	getDarkestSecret(void) const;
	private: 
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone_number;
		std::string _darkest_secret;
};

#endif