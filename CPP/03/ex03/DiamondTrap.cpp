/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 18:44:38 by aherrero          #+#    #+#             */
/*   Updated: 2022/10/01 17:29:54 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(), FragTrap(), ScavTrap()
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	this->name = "Default";
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name + "_frag_name"), ScavTrap(name + "_scav_name")
{
	std::cout << name << " DiamondTrap constructor called" << std::endl;
	this->name = name;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src)
{
    std::cout << "DiamondTrap copy constructor called" << std::endl;
    *this = src;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs)
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

// void		DiamondTrap::attack(std::string const & target)
// {
// 	ScavTrap::attack(target);
// 	std::cout << this->name << " has " << this->energy_points <<" energy points" << std::endl;
// }

void 	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap name: " << this->name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::name << std::endl;
}

void	DiamondTrap::print_values(void)
{
	std::cout << "Hit Points = " << this->hit_points << std::endl;
	std::cout << "Energy Points = " << this->energy_points << std::endl;
	std::cout << "Attack Damage = " << this->attack_damage << std::endl;
}
