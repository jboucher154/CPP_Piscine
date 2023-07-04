/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:19:04 by jebouche          #+#    #+#             */
/*   Updated: 2023/07/04 16:00:37 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void	process_line(std::string &line, std::string const to_find, std::string const replace_with) {

	size_t	position;
	
	position = line.find(to_find);
	while (position != std::string::npos) {
		line.erase(position, to_find.length());
		line.insert(position, replace_with); //may not need to be plus one
		position = line.find(to_find);
	}
}

void	replace_all(char *argv[]) {
	
	std::ifstream	inputFile(argv[1]);
	std::string		outputFName = argv[1]; outputFName.append(".replace");
	std::ofstream	outputFile(outputFName);
	std::string		line;

	if (inputFile.is_open() && outputFile.is_open()) {
		while (!inputFile.eof()) {
			std::getline(inputFile, line);
			process_line(line, argv[2], argv[3]);
			outputFile << line << std::endl;
		}
	}
	else
		std::cout << "Error: could not open files" << std::endl;
}

int	main(int argc, char *argv[]) {

	
	if (argc != 4) {
		std::cout << "Error: incorrect input: <filename> <string to find> <string to replace with>" << std::endl;
		return (1);
	}
	else 
		replace_all(argv);
	return (0);
}