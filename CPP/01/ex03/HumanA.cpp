/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 18:39:43 by aherrero          #+#    #+#             */
/*   Updated: 2022/09/13 17:28:14 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon){
	std::cout << "HumanA(" << name <<") constructor called" << std::endl;
	return ;
}

HumanA::~HumanA(void)
{
	std::cout << "HumanA(" << name <<") destructor called" << std::endl;
	return ;
}

void	HumanA::attack(void)
{
	std::cout << this->name << " attacks with his " << this->weapon.getType() << std::endl;
}
