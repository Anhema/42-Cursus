/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:47:36 by aherrero          #+#    #+#             */
/*   Updated: 2022/10/07 18:34:49 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	
	{
		DiamondTrap ander("Ander");

		ander.print_values();
		
		ander.attack("Someone");
		ander.takeDamage(6);
		ander.beRepaired(4);
		ander.takeDamage(3);
		ander.guardGate();
		ander.highFivesGuys();
		ander.whoAmI();
		ander.beRepaired(8);
		ander.takeDamage(17);
	}
	std::cout << "----------------------------------------" << std::endl;
	{
		FragTrap ander("Ander");

		ander.attack("Someone");
		ander.takeDamage(6);
		ander.beRepaired(4);
		ander.takeDamage(3);
		ander.highFivesGuys();
		ander.beRepaired(8);
		ander.takeDamage(17);
	}
	std::cout << "----------------------------------------" << std::endl;
	{
		ScavTrap ander("Ander");

		ander.attack("Someone");
		ander.takeDamage(6);
		ander.beRepaired(4);
		ander.takeDamage(3);
		ander.guardGate();
		ander.beRepaired(8);
		ander.takeDamage(17);
	}
	std::cout << "----------------------------------------" << std::endl;
	{
		ClapTrap ander("Ander");

		ander.attack("Someone");
		ander.takeDamage(6);
		ander.beRepaired(4);
		ander.takeDamage(3);
		ander.beRepaired(8);
		ander.takeDamage(17);
	}

	
	return (0);
}
