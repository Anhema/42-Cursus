/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:21:52 by aherrero          #+#    #+#             */
/*   Updated: 2022/11/01 11:32:23 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void)
{
	//std::cout << "Cure constructor called" << std::endl;
	this->type = "cure";
}

Cure::Cure(std::string const & type)
{
	//std::cout << "Cure constructor called" << std::endl;
	this->type = type;
}

Cure::~Cure(void)
{
	//std::cout << "Cure Destructor called" << std::endl;
}

Cure &Cure::operator=(const Cure &rhs)
{
	if (this != &rhs)
	{
		this->type = rhs.getType();
	}
	return (*this);
}

std::ostream & operator<<(std::ostream & o, Cure & i)
{
	o << i.getType();
	return (o);
}

AMateria* Cure::clone() const
{
	Cure *new_materia = new Cure();
	new_materia->type = this->getType();
	return (new_materia);
}

void Cure::use(ICharacter& target)
{
	std::cout << "Heal used in " << target.getName() << std::endl; 
}

std::string const & Cure::getType() const
{
	return (this->type);
}
