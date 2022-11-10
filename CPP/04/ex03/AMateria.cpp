/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:35:42 by aherrero          #+#    #+#             */
/*   Updated: 2022/11/01 11:28:34 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) : type("Default")
{
	//std::cout << "AMateria Constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) : type(type)
{
	//std::cout << "AMateria Constructor called" << std::endl;
}

AMateria::AMateria(AMateria const & src)
{
	//std::cout << "AMateria Copy constructor called" << std::endl;
	*this = src;
}

AMateria::~AMateria(void)
{
	//std::cout << "AMateria destructor called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &rhs)
{
	if (this != &rhs)
	{
		this->type = rhs.getType();
	}
	return (*this);
}

std::ostream & operator<<(std::ostream & o, AMateria & i)
{
	o << i.getType();
	return (o);
}

std::string const	&AMateria::getType() const
{
	return ((std::string const &)this->type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "Materia used against " << target.getName() << std::endl; 
}
