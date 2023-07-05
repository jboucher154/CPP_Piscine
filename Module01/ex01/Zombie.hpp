/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:45:02 by jebouche          #+#    #+#             */
/*   Updated: 2023/07/05 15:45:04 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie {
	public:
		Zombie( void );
		Zombie( std::string name );
		~Zombie( void );
		void	announce( void ); //const? public?

	private:
		std::string	_name;
};

#endif