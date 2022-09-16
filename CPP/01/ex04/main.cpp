/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:54:28 by aherrero          #+#    #+#             */
/*   Updated: 2022/09/16 17:18:17 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

std::string	read_file(std::string infile)
{
	std::string file;
	std::string line;
	std::ifstream ifs;

	ifs.open(infile);
	if (!ifs.is_open())
		return ("");
	while (std::getline(ifs, line))
	{
		file.append(line); 
		file.append("\n"); 
	}
	ifs.close();
	return (file);
}

std::string	replace(std::string file, std::string s1, std::string s2)
{
	std::string		result;
	size_t			i;
	size_t			n;

	i = 0;
	n = -1;
	if (s1 == "")
		return (file);
	while (file.find(s1, i) != n && file.find(s1, i) <= file.length())
	{
		n = file.find(s1, i);
		result.append(file, i, n - i);
		result.append(s2, 0, s2.length());
		i = n + s1.length();
	}
	result.append(file, i, n - i);
	if (result == "")
		result = file;
	return (result);
}

int main(int argc, char **argv)
{
	std::string		output_file;
	std::string		infile;

	if (argc != 4)
	{
		std::cout << "Invalid arguments: ./replace [input_file] [s1] [s2]" << std::endl;
		return (0);
	}
	infile = read_file(argv[1]);
	if (infile == "")
	{
		std::cout << "Invalid input file" << std::endl;
		return (0);
	}
	output_file = argv[1];
	std::ofstream ofs(output_file.append(".replace"));
	ofs << replace(infile, argv[2], argv[3]);;
	ofs.close();
	return (0);
}
