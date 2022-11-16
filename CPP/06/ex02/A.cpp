/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:33:39 by aherrero          #+#    #+#             */
/*   Updated: 2022/11/13 15:33:42 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"

A::A(void)
{
	return ;
}

A::A(const A &src)
{
	*this = src;
}

A::~A()
{
	
}

A &A::operator=(const A & rhs)
{
	(void)rhs;
	return (*this);
}

std::ostream & operator<<(std::ostream & o, A & i)
{
	(void)i;
	o << "A";
	return (o);
}
