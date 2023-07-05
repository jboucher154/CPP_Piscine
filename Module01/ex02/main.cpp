/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:45:33 by jebouche          #+#    #+#             */
/*   Updated: 2023/07/05 16:08:17 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main( void ) {
	std::string	str = "HI THIS IS BRIAN";
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