/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:45:49 by jebouche          #+#    #+#             */
/*   Updated: 2023/07/05 15:45:50 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

# include <string>
# include "Weapon.hpp"

class HumanA {
	public:
		HumanA( std::string name, Weapon &initial_Weapon );
		~HumanA();
		void	attack( void ) const;
	private:
		std::string	_name;
		Weapon		&_weapon;
};

#endif