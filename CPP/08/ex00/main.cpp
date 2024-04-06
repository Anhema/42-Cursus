/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:21:01 by aherrero          #+#    #+#             */
/*   Updated: 2022/11/26 10:45:57 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void)
{
	srand (time(NULL));

	std::vector<int> ar;
	std::cout << "vector<int> { ";
	for (size_t i = 0; i < 20; i++)
	{
		ar.push_back(rand() % 100);
		if (i < 19)
			std::cout << ar.back() << ", ";
		else
			std::cout << ar.back() << " }" << std::endl;
	}

	while (1)
	{
		int input = 0;

		std::cout << std::endl << "Insert a number: " ;
		std::cin >> input;
		if (!std::cin.good())
		{
			std::cout << std::endl << "Invalid input, please try again" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue ;
		}
		std::cout << std::endl;
		try
		{
			easyfind(ar, input);
			std::cout << "Found " << input << " in vector" << std::endl;
			break;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Cannot found " << input << " in vector" << std::endl;
		}
	}
	
	return (0);
}
