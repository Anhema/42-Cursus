/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:19:48 by aherrero          #+#    #+#             */
/*   Updated: 2022/10/30 17:16:24 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"

int main()
{
	{
		Dog dog;
		Animal *anim = new Cat();
		
		anim->makeSound();
		dog.makeSound();
	}
	// {
	// 	Animal tmp;
	// }
	return 0;
}
