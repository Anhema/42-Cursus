/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:05:01 by aherrero          #+#    #+#             */
/*   Updated: 2022/10/06 16:03:32 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	std::cout << "WrongAnimal constructor called" << std::endl;
	this->type = "Default";
}

WrongAnimal::WrongAnimal(std::string type)
{
	std::cout << "WrongAnimal constructor called" << std::endl;
	this->type = type;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	*this = src;
	return;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs)
{
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

std::string WrongAnimal::getType()
{
	return(this->type);
}

std::ostream & operator<<(std::ostream & o, WrongAnimal & i)
{
	o << i.getType();
	return (o);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << this->type << " make sound (WrongAnimal)" << std::endl;
}
