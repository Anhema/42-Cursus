/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:20:11 by aherrero          #+#    #+#             */
/*   Updated: 2022/10/06 16:14:54 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("Cat")
{
	std::cout << "WrongCat constructor called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &src)
{
	*this = src;
	return;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &rhs)
{
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

std::ostream & operator<<(std::ostream & o, WrongCat & i)
{
	o << i.getType();
	return (o);
}

void	WrongCat::makeSound(void) const
{
	std::cout << this->type << " make sound (MEOW!!)" << std::endl;
}
