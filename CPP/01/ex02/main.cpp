/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 18:11:59 by aherrero          #+#    #+#             */
/*   Updated: 2022/09/12 18:34:56 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	
	std::string	*strPTR = &str;
	std::string	&strREF = str;

	std::cout << "string = " << str << std::endl;
	std::cout << "stringPTR = " << *strPTR << std::endl;
	std::cout << "stringREF = " << strREF << std::endl;
	return (0);
}
