/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:45:57 by jebouche          #+#    #+#             */
/*   Updated: 2023/07/05 20:06:55 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

# include <string>
# include "Weapon.hpp"

class HumanB {
	public:
		HumanB( std::string name);
		~HumanB();
		void	attack( void ) const;
		void	setWeapon( Weapon &new_weapon );
	private:
		std::string	_name;
		Weapon		*_weapon;
};

#endif