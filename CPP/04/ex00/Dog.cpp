/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:12:14 by aherrero          #+#    #+#             */
/*   Updated: 2022/10/30 16:15:17 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Dog constructor called" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog &src)
{
	*this = src;
	return;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &rhs)
{
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

std::ostream & operator<<(std::ostream & o, Dog & i)
{
	o << i.getType();
	return (o);
}

void	Dog::makeSound(void) const
{
	std::cout << this->type << " make sound (WOUF!!)" << std::endl;
}
