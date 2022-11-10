/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:20:22 by aherrero          #+#    #+#             */
/*   Updated: 2022/10/07 18:49:46 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
 #define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public Animal
{
	public:
		Cat(void);
		Cat(Cat const & src);
		virtual ~Cat(void);
		Cat & operator=(Cat const & rhs);

		void makeSound(void);
		Brain	*get_brain(void) const;
		std::string getType() const;

	private:
		Brain *brain;
};

std::ostream & operator<<(std::ostream & o, Cat & i);

#endif
