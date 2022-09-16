/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:21:18 by aherrero          #+#    #+#             */
/*   Updated: 2022/09/15 18:32:50 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Invalid Input: ./karenFilter [STR]" << std::endl;
		return (0);
	}
	
	Karen	karen;
	karen.complain((std::string)argv[1]);
	return (0);
}
