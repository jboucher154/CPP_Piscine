/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:29:51 by jebouche          #+#    #+#             */
/*   Updated: 2023/07/17 10:48:08 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <iostream>

class Harl
{
	public:
		Harl( void );
		~Harl( void );
		void	complain( std::string level);

	private:
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );
};

#endif