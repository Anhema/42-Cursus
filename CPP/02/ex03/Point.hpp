/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:43:24 by aherrero          #+#    #+#             */
/*   Updated: 2022/09/22 17:56:15 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
 #define POINT_HPP

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

class Point
{
	public:
		Point(void);
		Point(Fixed x, Fixed y);
		Point(Point const & src);
		~Point(void);

		Fixed getX(void) const;
		Fixed getY(void) const;

		Point & operator=(Point const & rhs);		
	private:
		Fixed const	x;
		Fixed const	y;
};

std::ostream & operator<<(std::ostream & o, Point const & rhs);
bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
