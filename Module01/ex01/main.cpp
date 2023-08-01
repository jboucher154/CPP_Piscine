/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:44:47 by jebouche          #+#    #+#             */
/*   Updated: 2023/08/01 11:53:47 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name );

int	main( void ) {

	int	count = 42;
	Zombie *horde = zombieHorde(count, "Tyson");
	for (int i = 0; i < count; i++) {
		horde[i].announce();
	}
	delete [] horde;
	return (0);
}
