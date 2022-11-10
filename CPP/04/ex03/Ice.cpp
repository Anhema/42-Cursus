/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:13:45 by aherrero          #+#    #+#             */
/*   Updated: 2022/11/01 11:32:01 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void)
{
	//std::cout << "Ice constructor called" << std::endl;
	this->type = "ice";
}

Ice::Ice(std::string const & type)
{
	//std::cout << "Ice constructor called" << std::endl;
	this->type = type;
}

Ice::~Ice(void)
{
	//std::cout << "Ice Destructor called" << std::endl;
}

Ice &Ice::operator=(const Ice &rhs)
{
	if (this != &rhs)
	{
		this->type = rhs.getType();
	}
	return (*this);
}

std::ostream & operator<<(std::ostream & o, Ice & i)
{
	o << i.getType();
	return (o);
}

AMateria* Ice::clone() const
{
	Ice *new_materia = new Ice();
	new_materia->type = this->getType();
	return (new_materia);
}

void Ice::use(ICharacter& target)
{
	std::cout << "Ice used against " << target.getName() << std::endl; 
}

std::string const & Ice::getType() const
{
	return (this->type);
}
