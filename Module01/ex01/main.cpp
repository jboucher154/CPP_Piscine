/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:44:47 by jebouche          #+#    #+#             */
/*   Updated: 2023/07/05 15:44:49 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name );

int	main( void ) {

	int	count = 10;
	Zombie *horde = zombieHorde(count, "Tyson");
	for (int i = 0; i < count; i++) {
		horde->announce();
	}
	delete [] horde;
	return (0);
}
