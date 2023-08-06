/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:44:47 by jebouche          #+#    #+#             */
/*   Updated: 2023/08/06 14:17:17 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name );

int	main( void ) {
	{	
		int	count = 42;
		Zombie *horde = zombieHorde(count, "Tyson");
		for (int i = 0; i < count; i++) {
			horde[i].announce();
		}
		delete [] horde;
	}
	{	
		int	count = -1;
		Zombie *horde = zombieHorde(count, "Shelly");
		for (int i = 0; i < count; i++) {
			horde[i].announce();
		}
		delete [] horde;
	}
	{	
		int	count = 0;
		Zombie *horde = zombieHorde(count, "Brian");
		for (int i = 0; i < count; i++) {
			horde[i].announce();
		}
		delete [] horde;
	}
	return (0);
}
