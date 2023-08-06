/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:46:52 by jebouche          #+#    #+#             */
/*   Updated: 2023/08/06 14:38:12 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include "Color.hpp"

Harl::Harl( void ) {
	std::cout <<  "Hiiiiiiiii!" << std::endl;
}

Harl::~Harl( void ) {
	std::cout <<  "Byyyyyyeee!" << std::endl;
}

void	Harl::complain( std::string level) {
	void (Harl::*c[4]) (void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	std::string	levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };

	for (int i = 0; i < 4; i++) {
		if (!level.compare(levels[i])) {
			(this->*c[i])();
		}
	}
}

void	Harl::debug( void ) {
	std::cout << COLOR_BRIGHT_CYAN;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
	std::cout << COLOR_RESET;
}

void	Harl::info( void ) {
	std::cout << COLOR_BRIGHT_YELLOW;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
	std::cout << COLOR_RESET;
}

void	Harl::warning( void ) {
	std::cout << COLOR_BRIGHT_GREEN;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
	std::cout << COLOR_RESET;
}

void	Harl::error( void ) {
	std::cout << COLOR_BRIGHT_RED;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	std::cout << COLOR_RESET;
}
