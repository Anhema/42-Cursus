/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:38:17 by aherrero          #+#    #+#             */
/*   Updated: 2022/09/23 15:54:00 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main(void)
{
    Point a(0.0f, 0.0f), b(2.0f, 0.0f), c(1.0f, 2.0f);
    Point p1(1.0f, 1.0f), p2(0.0f, 0.5f), p3(-0.1f, 0.0f), p4(-0.1f, -0.1f);

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "p1 = " << p1 << std::endl;
	std::cout << "p2 = " << p2 << std::endl;
	std::cout << "p3 = " << p3 << std::endl;
	std::cout << "p4 = " << p4 << std::endl << std::endl;
	std::cout << "p1 ";
	if (bsp(a, b, c, p1))
		std::cout << "point is Inside the triagle" << std::endl << std::endl;
	else
		std::cout << "point is Outside the triagle" << std::endl << std::endl;
	std::cout << "p2 ";
	if (bsp(a, b, c, p2))
		std::cout << "point is Inside the triagle" << std::endl << std::endl;
	else
		std::cout << "point is Outside the triagle" << std::endl << std::endl;
	std::cout << "p3 ";
	if (bsp(a, b, c, p3))
		std::cout << "point is Inside the triagle" << std::endl << std::endl;
	else
		std::cout << "point is Outside the triagle" << std::endl << std::endl;
	std::cout << "p4 ";
	if (bsp(a, b, c, p4))
		std::cout << "point is Inside the triagle" << std::endl << std::endl;
	else
		std::cout << "point is Outside the triagle" << std::endl << std::endl;

	return (0);
}
