/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:46:21 by jebouche          #+#    #+#             */
/*   Updated: 2023/07/05 15:46:22 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class	Weapon {
	public:
		Weapon( void );
		Weapon( std::string type );
		~Weapon( void );
		std::string	const &getType( void );
		void	setType(std::string new_type);

	private: 
		std::string	_type;
};

#endif