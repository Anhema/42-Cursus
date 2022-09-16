/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 18:40:44 by aherrero          #+#    #+#             */
/*   Updated: 2022/09/16 16:14:54 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zombie;
	int		i;
	int		n = 5;

	zombie = zombieHorde(n, "Ander");
	i = 0;
	while (i < n)
		zombie[i++].announce();
	delete[] zombie;
	return (0);
}
