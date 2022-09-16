/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 18:40:46 by aherrero          #+#    #+#             */
/*   Updated: 2022/09/16 16:13:42 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "New Zombie created" << std::endl;
	return;
}

Zombie::~Zombie(void)
{
	std::cout << this->name << " Destroyed" << std::endl;
	return;
}

void Zombie::announce(void)
{
	std::cout << this->name << " BraiiiiiiinnnzzzZ..." << std::endl;
	return;
}

void Zombie::set_name(std::string name)
{
	this->name = name;
	return;
}
