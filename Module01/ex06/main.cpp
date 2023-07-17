/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:47:18 by jebouche          #+#    #+#             */
/*   Updated: 2023/07/17 10:51:05 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include "Color.hpp"

void	filter( const std::string &filter_level)
{
	Harl		harl_one;
	std::string	levels[] = { "DEBUG", "INFO", "WARNING", "ERROR"};
	int 		filter = 5;
	
	for (int i = 0; i < 4; i++) {
		if (!filter_level.compare(levels[i]))
		{
			filter = i;
			break ;
		}
	}
	switch (filter)
	{
		case 0:
			harl_one.complain(levels[0]);
		case 1:
			harl_one.complain(levels[1]);
		case 2:
			harl_one.complain(levels[2]);
		case 3:
			harl_one.complain(levels[3]);
			break;
		default:
			std::cout << COLOR_BRIGHT_MAGENTA << "[ Probably complaining about insignificant problems ]" << COLOR_RESET << std::endl;
			break;
	}
}

int	main( int argc, char *argv[] ) {

	if (argc != 2)
	{
		std::cerr << COLOR_RED << "Error: incorrect input: enter <filter level>" << COLOR_RESET << std::endl;
		return (1);
	}
	filter(argv[1]);
	return (0);
}
