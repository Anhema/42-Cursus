/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:34:44 by aherrero          #+#    #+#             */
/*   Updated: 2022/10/07 18:51:26 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
 #define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public Animal
{
	public:
		Dog(void);
		Dog(Dog const & src);
		virtual ~Dog(void);
		Dog & operator=(const Dog & rhs);

		void makeSound(void);
		Brain	*get_brain(void) const;
		std::string getType() const;


	private:
		Brain *brain;
};

std::ostream & operator<<(std::ostream & o, Dog & i);

#endif
