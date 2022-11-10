/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 18:44:38 by aherrero          #+#    #+#             */
/*   Updated: 2022/09/29 16:42:39 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	std::cout << "FragTrap default constructor called" << std::endl;
	this->attack_damage = 30;
	this->energy_points = 100;
	this->hit_points = 100;
	this->name = "Default";
}

FragTrap::FragTrap(std::string name)
{
	std::cout << name << " FragTrap constructor called" << std::endl;
	this->attack_damage = 30;
	this->energy_points = 100;
	this->hit_points = 100;
	this->name = name;
}

FragTrap::FragTrap(const FragTrap &src)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
    *this = src;
    return;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs)
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

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap high fives reques" << std::endl;	
}
