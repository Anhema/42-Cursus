/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:33:17 by aherrero          #+#    #+#             */
/*   Updated: 2022/10/01 13:13:40 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


ClapTrap::ClapTrap(void) : name("Default"), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << name << " ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = src;
    return;
}

ClapTrap::~ClapTrap()
{
	std::cout << this->name << " ClapTrap destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
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

void	ClapTrap::attack(std::string const & target)
{
	if (this->energy_points <= 0)
	{
		std::cout << "ClapTrap " << this->name << " has no energy points" << std::endl;
		return ;
	}
	this->energy_points--;
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << get_attack_damage() << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{	
	this->hit_points -= amount;
	std::cout << this->name << " recived " << get_attack_damage() << " points of damage! " << this->hit_points  << " life points left" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	this->hit_points += amount;
	std::cout << this->name << " recover " << amount << " life points! " << this->hit_points  << " life points left" << std::endl;
}

int		ClapTrap::get_attack_damage(void)
{
	return (this->attack_damage);
}

int		ClapTrap::get_energy_points(void)
{
	return (this->energy_points);
}

int		ClapTrap::get_hit_points(void)
{
	return (this->hit_points);
}
