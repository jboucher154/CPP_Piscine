/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:19:04 by jebouche          #+#    #+#             */
/*   Updated: 2023/08/01 15:16:26 by jebouche         ###   ########.fr       */
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
		position = line.find(to_find, position + replace_with.length());
	}
}

void	replace_all(std::string fname, std::string to_find, std::string replace_with) {
	
	std::ifstream	inputFile(fname);
	std::string		outputFName = fname; 
	outputFName.append(".replace");
	std::string		line;

	if (inputFile.is_open()) {
		std::ofstream	outputFile(outputFName);
		if (outputFile.is_open())
		{
			while (!inputFile.eof()) {
				std::getline(inputFile, line);
				if (!inputFile.eof())
					line.append("\n");
				process_line(line, to_find, replace_with);
				outputFile << line;
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
			std::cerr << "Error: could not open " << fname << " file" << std::endl;			
	}
}

int	main(int argc, char *argv[]) {

	if (argc != 4) {
		std::cerr << "Error: incorrect input: <filename> <string to find> <string to replace with>" << std::endl;
		return (1);
	}
	else if (argv[1][0] && argv[2][0] && argv[3][0]) {

		replace_all(argv[1], argv[2], argv[3]);
	}
	else {
		std::cerr << "Error: do not pass empty strings as arguments" << std::endl;
	}
	return (0);
}
