/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 18:40:44 by aherrero          #+#    #+#             */
/*   Updated: 2022/09/12 17:40:47 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie *zombie;

	std::cout << "<allocate on the heap>" << std::endl;
	zombie = newZombie("Zombie_1");
	delete(zombie);
	std::cout << "<allocate on the stack>" << std::endl;
	randomChump("Zombie_2");
	return (0);
}
