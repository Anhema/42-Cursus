/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:47:36 by aherrero          #+#    #+#             */
/*   Updated: 2022/10/01 17:11:55 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
		ClapTrap ander("Ander");

		ander.attack("Someone");
		ander.takeDamage(6);
		ander.beRepaired(4);
		ander.takeDamage(3);
		ander.beRepaired(8);
		ander.takeDamage(17);
	
	return (0);
}
