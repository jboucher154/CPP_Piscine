/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:19:04 by jebouche          #+#    #+#             */
/*   Updated: 2023/07/17 10:45:06 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void	process_line(std::string &line, std::string const &to_find, std::string const &replace_with) {

	size_t	position;
	
	position = line.find(to_find);
	while (position != std::string::npos) {
		line.erase(position, to_find.length());
		line.insert(position, replace_with);
		position = line.find(to_find);
	}
}

void	replace_all(char *argv[]) {
	
	std::ifstream	inputFile(argv[1]);
	std::string		outputFName = argv[1]; 
	outputFName.append(".replace");
	std::string		line;

	if (inputFile.is_open()) {
		std::ofstream	outputFile(outputFName);
		if (outputFile.is_open())
		{
			while (!inputFile.eof()) {
				std::getline(inputFile, line);
				process_line(line, argv[2], argv[3]);
				outputFile << line << std::endl;
			}
			outputFile.close();
		}
		else {
			std::cerr << "Error: could not open " << outputFName << " file" << std::endl;
		}
		inputFile.close();
	}
	else {
		if (!inputFile.is_open())
			std::cerr << "Error: could not open " << argv[1] << " file" << std::endl;			
	}
}

int	main(int argc, char *argv[]) {

	if (argc != 4) {
		std::cerr << "Error: incorrect input: <filename> <string to find> <string to replace with>" << std::endl;
		return (1);
	}
	else 
		replace_all(argv);
	return (0);
}
