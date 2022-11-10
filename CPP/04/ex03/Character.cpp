/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:04:07 by aherrero          #+#    #+#             */
/*   Updated: 2022/11/01 11:41:24 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void)
{
	//std::cout << "Charcater Constructor called" << std::endl;
	this->name = "Default";
	for (size_t i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character(std::string name)
{
	//std::cout << "Charcater Constructor called" << std::endl;
	this->name = name;
	for (size_t i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character(Character const & src)
{
	//std::cout << "Character Copy constructor called" << std::endl;
	this->name = src.getName();
	for (size_t i = 0; i < 4; i++)
	{
		if (src.inventory[i] != NULL)
			this->inventory[i] = src.inventory[i]->clone();
	}
	//*this = src;
}

Character::~Character(void)
{
	//std::cout << "Character destructor called" << std::endl;
	for (size_t i = 0; i < 4; i++)
	{
		if (this->inventory[i] != NULL)
			delete (this->inventory[i]);
	}
}

Character &Character::operator=(const Character &rhs)
{
	if (this != &rhs)
	{
		this->name = rhs.getName();
		for (size_t i = 0; i < 4; i++)
		{
			if (rhs.inventory[i] != NULL)
				this->inventory[i] = rhs.inventory[i]->clone();
		}
	}
	return (*this);
}

std::ostream & operator<<(std::ostream & o, Character & i)
{
	o << i.getName();
	return (o);
}

std::string const & Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria* m)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (this->inventory[i] == NULL)
		{
			this->inventory[i] = m;
//			std::cout << this->getName() << " equiped " << m->getType() << std::endl;
			return;
		}
	}
	std::cout << this->getName() << " inventory is full"<< std::endl;
}

void Character::unequip(int idx)
{
//	std::cout << this->getName() << " deleted " << this->inventory[idx]->getType() << std::endl;
	delete (this->inventory[idx]);
	this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (this->inventory[idx])
	{
		//std::cout << this->inventory[idx]->getType() << std::endl;
		if (this->inventory[idx]->getType() == "ice")
			std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
		else
			std::cout << "* heal " << target.getName() << "'s wounds *" << std::endl;
		delete (this->inventory[idx]);
		this->inventory[idx] = NULL;
	}
}
