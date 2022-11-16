/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:42:59 by aherrero          #+#    #+#             */
/*   Updated: 2022/11/13 15:33:29 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "C.hpp"

C::C(void)
{
	return ;
}

C::C(const C &src)
{
	*this = src;
}

C::~C()
{
	
}

C &C::operator=(const C & rhs)
{
	(void)rhs;
	return (*this);
}

std::ostream & operator<<(std::ostream & o, C & i)
{
	(void)i;
	o << "C";
	return (o);
}
