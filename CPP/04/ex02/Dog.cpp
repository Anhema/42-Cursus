/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:12:14 by aherrero          #+#    #+#             */
/*   Updated: 2022/10/07 18:51:59 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	this->brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog &src)
{
	std::cout << "Dog deep copy constructor called" << std::endl;
	this->brain = new Brain();
	*this->brain = *src.get_brain();
	this->type = src.getType();
}

Dog::~Dog(void)
{
	delete(this->brain);
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &rhs)
{
	if (this != &rhs)
	{
		delete (this->brain);
		this->brain = new Brain();
		*this->brain = *rhs.get_brain();
		this->type = rhs.getType();
		
	}
	return (*this);
}

std::ostream & operator<<(std::ostream & o, Dog & i)
{
	o << i.getType();
	return (o);
}

std::string Dog::getType() const
{
	return(this->type);
}

void	Dog::makeSound(void)
{
	std::cout << this->type << " make sound (WOUF!!)" << std::endl;
}

Brain	*Dog::get_brain(void) const
{
	return (this->brain);
}
