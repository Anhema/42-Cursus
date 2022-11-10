/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:19:48 by aherrero          #+#    #+#             */
/*   Updated: 2022/10/30 17:14:53 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"

int main()
{
	std::cout << "Deep copy" << std::endl << std::endl;
	Dog basic;
	{
		Dog tmp = basic;
	}
	std::cout << std::endl << "---------------" << std::endl;
	std::cout << "Subject main" << std::endl << std::endl;
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		
		delete (j);
		delete (i);
	}
	std::cout << std::endl << "---------------" << std::endl;
	std::cout << "Animal List" << std::endl << std::endl;
	{
		Animal 	*lst[4];
		for (size_t i = 0; i < 4; i++)
		{
			if (i % 2 == 0)
				lst[i] = new Dog();	
			else
				lst[i] = new Cat();
		}
		for (size_t i = 0; i < 4; i++)
		{
			delete (lst[i]);
		}
	}
	return 0;
}
