/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:19:48 by aherrero          #+#    #+#             */
/*   Updated: 2022/10/30 16:09:10 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"

int main()
{
	{
		Animal* meta = new Animal();
		Animal* j = new Dog();
		Animal* i = new Cat();

		std::cout << j->getType() << std::endl;
		std::cout << i->getType() << std::endl;
		std::cout << meta->getType() << std::endl;
		i->makeSound();
		j->makeSound();
		meta->makeSound();

		delete (meta);
		delete (i);
		delete (j);
	}
	std::cout << std::endl << "----------------------" << std::endl;
	std::cout << "Wrong test" << std::endl << std::endl;
	{
		WrongAnimal *meta = new WrongAnimal();
		WrongAnimal *cat = new WrongCat();

		std::cout << cat->getType() << std::endl;
		meta->makeSound();
		cat->makeSound();

		delete (meta);
		delete (cat);
	}
	return 0;
}
