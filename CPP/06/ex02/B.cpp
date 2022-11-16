/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:42:23 by aherrero          #+#    #+#             */
/*   Updated: 2022/11/13 15:33:38 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "B.hpp"

B::B(void)
{
	return ;
}

B::B(const B &src)
{
	*this = src;
}

B::~B()
{
	
}

B &B::operator=(const B & rhs)
{
	(void)rhs;
	return (*this);
}

std::ostream & operator<<(std::ostream & o, B & i)
{
	(void)i;
	o << "B";
	return (o);
}
