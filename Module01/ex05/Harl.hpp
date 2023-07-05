/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:29:51 by jebouche          #+#    #+#             */
/*   Updated: 2023/07/05 11:38:09 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>

# define COLOR_RESET "\033[0m"
# define COLOR_BRIGHT_RED "\033[91m"
# define COLOR_BRIGHT_GREEN "\033[92m"
# define COLOR_BRIGHT_YELLOW "\033[93m"
# define COLOR_BRIGHT_CYAN "\033[96m"
# define COLOR_BRIGHT_MAGENTA "\033[95m"
# define BGCOLOR_PURPLE_BLUE "\033[1;36;45m"

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