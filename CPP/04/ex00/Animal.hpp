/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:03:02 by aherrero          #+#    #+#             */
/*   Updated: 2022/10/06 16:43:00 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
 #define ANIMAL_HPP

#include <iostream>

class Animal
{
	public:
		Animal(void);
		Animal(std::string type);
		Animal(Animal const & src);
		virtual ~Animal(void);
		Animal & operator=(Animal const & rhs);

		std::string getType(void);
		virtual void makeSound(void) const;

	protected:
		std::string type;
};

std::ostream & operator<<(std::ostream & o, Animal & i);

#endif
