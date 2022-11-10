/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:03:02 by aherrero          #+#    #+#             */
/*   Updated: 2022/10/06 16:04:28 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
 #define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal(void);
		WrongAnimal(std::string type);
		WrongAnimal(WrongAnimal const & src);
		virtual ~WrongAnimal();
		WrongAnimal & operator=(WrongAnimal const & rhs);

		std::string getType();
		void makeSound(void) const;

	protected:
		std::string type;
};

std::ostream & operator<<(std::ostream & o, WrongAnimal & i);

#endif
