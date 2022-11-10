/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:43:42 by aherrero          #+#    #+#             */
/*   Updated: 2022/09/23 15:54:18 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed	get_area(Fixed w, Fixed h)
{
	Fixed	result;

	result = (w * h) / 2;
	return (result);
}

Fixed	get_width(Point const p1, Point const p2)
{
	Fixed result;

	result = p2.getX() - p1.getX();
	if (result < 0)
		result = result * -1;
	return (result);
}

Fixed	get_dist(Point const p1, Point const p2)
{
	Fixed result;
	Fixed dx,dy;

	dx = (p1.getX() - p2.getX());
	dy = (p1.getY() - p2.getY());
	result = dx - dy;
	if (result < 0)
		result = result * -1;
	return (result);
}

Fixed	get_height(Point const p1, Point const p2, Point const p3)
{
	Fixed result;
	Fixed a,b;

	(void)p1;
	a = p2.getX() - p3.getX();
	b = get_dist(p2, p3);
	result = b - a;
	if (result < 0)
		result = result * -1;
	return (result);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	area_abc = get_area(get_width(a, b), get_height(a, b, c));
	Fixed	area_abp = get_area(get_width(a, b), get_height(a, b, point));
	Fixed	area_bcp = get_area(get_width(b, c), get_height(b, c, point));
	Fixed	area_acp = get_area(get_width(a, c), get_height(a, c, point));

	if ((area_abp + area_bcp + area_acp) == area_abc)
		return (true);
	else
		return (false);
	return (true);
}
