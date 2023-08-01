/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:45:33 by jebouche          #+#    #+#             */
/*   Updated: 2023/08/01 16:36:10 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main( void ) {
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Addresses are:" << std::endl;
	std::cout << "str: " << &str;
	std::cout << 	", stringPTR: " << stringPTR;
	std::cout  << ", stringREF: " << &stringREF << std::endl;

	std::cout << "Values are:" << std::endl;
	std::cout << "str: " << str;
	std::cout << 	", stringPTR: " << *stringPTR;
	std::cout  << ", stringREF: " << stringREF << std::endl;
	return (0);
}