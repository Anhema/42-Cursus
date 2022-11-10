/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:03:02 by aherrero          #+#    #+#             */
/*   Updated: 2022/10/30 16:38:40 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
 #define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class Animal
{
	public:
		Animal(void);
		Animal(std::string type);
		Animal(Animal const & src);
		virtual ~Animal();
		virtual Animal & operator=(Animal const & rhs);

		std::string getType() const;
		virtual void makeSound(void) const;
		virtual Brain	*get_brain(void) const = 0;

	protected:
		std::string type;
};

std::ostream & operator<<(std::ostream & o, Animal & i);

#endif
