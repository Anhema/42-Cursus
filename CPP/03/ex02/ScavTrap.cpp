/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 18:44:38 by aherrero          #+#    #+#             */
/*   Updated: 2022/10/01 12:59:07 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->attack_damage = 20;
	this->energy_points = 50;
	this->hit_points = 100;
	this->name = "Default";
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << name << " ScavTrap constructor called" << std::endl;
	this->attack_damage = 20;
	this->energy_points = 50;
	this->hit_points = 100;
	this->name = name;
}

ScavTrap::ScavTrap(const ScavTrap &src)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
    *this = src;
    return;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
	if (this != &rhs)
	{
		this->attack_damage = rhs.attack_damage;
		this->energy_points = rhs.energy_points;
		this->hit_points = rhs.hit_points;
		this->name = rhs.name;
	}
	return (*this);
}

void		ScavTrap::attack(std::string const & target)
{
	std::cout << "ScavTrap " << this->name << " attack " << target << " causing " << this->attack_damage << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap have enterred in Gate keeper mode" << std::endl;	
}
