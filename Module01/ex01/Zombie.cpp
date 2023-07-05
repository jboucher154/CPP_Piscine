/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:44:58 by jebouche          #+#    #+#             */
/*   Updated: 2023/07/05 16:03:00 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie( void ) {
	std::cout << "Zombie created" << std::endl;
}

Zombie::Zombie( std::string name ) : _name(name) {
	std::cout << "Zombie " << this->_name << " created" << std::endl;
}

Zombie::~Zombie( void ) {
	std::cout << "Zombie " << this->_name << " destroyed" << std::endl;
}

void	Zombie::announce( void ) {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName( std::string name ) {
	this->_name = name;
}