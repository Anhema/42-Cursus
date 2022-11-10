/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:38:17 by aherrero          #+#    #+#             */
/*   Updated: 2022/10/21 16:52:57 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed a;
	Fixed test(42.42f);
	Fixed test2(12020.1f);
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << test2 / test << std::endl;

	std::cout << b << std::endl;
	
	std::cout << Fixed::max(a, b) << std::endl;

	if (a > b)
		std::cout << "a is bigger than b" << std::endl;

	if (a < b)
		std::cout << "a is lower than b" << std::endl;
		
	if (a == b)
		std::cout << "a and b are equals" << std::endl;
	return (0);
}
