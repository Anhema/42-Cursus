/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:05:01 by aherrero          #+#    #+#             */
/*   Updated: 2022/10/07 19:09:16 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Animal constructor called" << std::endl;
	this->type = "Default";
}

Animal::Animal(std::string type)
{
	std::cout << "Animal constructor called" << std::endl;
	this->type = type;
}

Animal::Animal(const Animal &src)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
	return;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &rhs)
{
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

std::ostream & operator<<(std::ostream & o, Animal & i)
{
	o << i.getType();
	return (o);
}

std::string Animal::getType() const
{
	return(this->type);
}
