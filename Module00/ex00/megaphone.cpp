/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:37:18 by jebouche          #+#    #+#             */
/*   Updated: 2023/06/29 16:37:21 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char* argv[])
{
	char ch;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < argc; i++)
	{
		for (size_t j = 0; j < std::strlen(argv[i]); j++)
		{
			ch = std::toupper(argv[i][j]);
			std::cout << ch;
		}
	}
	std::cout << '\n';
	return 0;
}
