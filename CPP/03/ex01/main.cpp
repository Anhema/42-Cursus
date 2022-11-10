/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:47:36 by aherrero          #+#    #+#             */
/*   Updated: 2022/10/01 17:22:17 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap ander("Ander");

	ander.attack("Someone");
	ander.takeDamage(6);
	ander.beRepaired(4);
	ander.takeDamage(3);
	ander.beRepaired(8);
	ander.takeDamage(17);

	std::cout << "----------------------------------------" << std::endl;

	ClapTrap _ander("Ander");

	_ander.attack("Someone");
	_ander.takeDamage(6);
	_ander.beRepaired(4);
	_ander.takeDamage(3);
	_ander.beRepaired(8);
	_ander.takeDamage(17);

	return (0);
}
