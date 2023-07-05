/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:45:08 by jebouche          #+#    #+#             */
/*   Updated: 2023/07/05 15:45:10 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name ) {
	Zombie *horde = new Zombie[N];
	
	for (int i = 0; i < N; i++) {
		horde[i] = Zombie(name);
	}
	return (horde);
}