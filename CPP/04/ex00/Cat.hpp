/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:20:22 by aherrero          #+#    #+#             */
/*   Updated: 2022/10/06 16:05:01 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
 #define CAT_HPP

#include "Animal.hpp"
#include <iostream>

class Cat : public Animal
{
	public:
		Cat(void);
		Cat(Cat const & src);
		~Cat(void);
		Cat & operator=(Cat const & rhs);

		virtual void makeSound(void) const;

	protected:
		std::string type;
};

std::ostream & operator<<(std::ostream & o, Cat & i);

#endif
