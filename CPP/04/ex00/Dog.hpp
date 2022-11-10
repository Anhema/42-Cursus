/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:34:44 by aherrero          #+#    #+#             */
/*   Updated: 2022/10/06 16:29:18 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
 #define DOG_HPP

#include "Animal.hpp"
#include <iostream>

class Dog : public Animal
{
	public:
		Dog(void);
		Dog(Dog const & src);
		~Dog(void);
		Dog & operator=(Dog const & rhs);

		virtual void makeSound(void) const;

	protected:
		std::string type;
};

std::ostream & operator<<(std::ostream & o, Dog & i);

#endif
