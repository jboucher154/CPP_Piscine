/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:19:04 by jebouche          #+#    #+#             */
/*   Updated: 2023/08/06 14:21:58 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void	process_file(std::string &file, std::string const &to_find, std::string const &replace_with) {

	size_t	position;
	
	position = file.find(to_find);
	while (position != std::string::npos) {
		file.erase(position, to_find.length());
		file.insert(position, replace_with);
		position = file.find(to_find, position + replace_with.length());
	}
}

void	replace_all(std::string fname, std::string to_find, std::string replace_with) {
	
	std::ifstream	inputFile(fname);
	std::string		outputFName = fname; 
	outputFName.append(".replace");
	std::string		line;
	std::string		file_contents;

	if (inputFile.is_open()) {
		std::ofstream	outputFile(outputFName);
		if (outputFile.is_open())
		{
			while (!inputFile.eof()) {
				std::getline(inputFile, line);
				if (!inputFile.eof())
					line.append("\n");
				file_contents.append(line);
			}
			process_file(file_contents, to_find, replace_with);
			outputFile << file_contents;
			outputFile.close();
		}
		else {
			std::cerr << "Error: could not open " << outputFName << " file" << std::endl;
		}
		inputFile.close();
	}
	else {
		std::cerr << "Error: could not open " << fname << " file" << std::endl;			
	}
}

int	main(int argc, char *argv[]) {

	if (argc != 4) {
		std::cerr << "Error: incorrect input: <filename> <string to find> <string to replace with>" << std::endl;
		return (1);
	}
	else if (argv[1][0] && argv[2][0]) {

		replace_all(argv[1], argv[2], argv[3]);
	}
	else {
		std::cerr << "Error: do not pass empty strings as arguments" << std::endl;
	}
	return (0);
}
