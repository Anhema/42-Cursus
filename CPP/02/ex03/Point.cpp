/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:43:33 by aherrero          #+#    #+#             */
/*   Updated: 2022/09/22 18:42:40 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : x(0), y(0)
{
	//std::cout << "(POINT) Default constructor called" << std::endl;
}

Point::Point(Fixed const x, Fixed const y) : x(x), y(y)
{
	//std::cout << "(POINT) Fixed constructor called" << std::endl;
}

Point::Point(const Point &src)
{
	//std::cout << "(POINT) Copy constructor called" << std::endl;
	*this = src;
	return;
}

Point::~Point(void)
{
	//std::cout << "(POINT) Destructor called" << std::endl;
}

Fixed Point::getX(void) const
{
	return (this->x);
}

Fixed Point::getY(void) const
{
	return (this->y);
}


Point &Point::operator=(Point const &rhs)
{
	//std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs)
	{
		const_cast<Fixed&>(this->x) = rhs.getX();
		const_cast<Fixed&>(this->y) = rhs.getY();
	}
	return (*this);
}

std::ostream & operator<<(std::ostream & o, Point const & point)
{
	o << "("<< point.getX() << ", " << point.getY() << ")";
	return (o);
}

