/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:20:22 by aherrero          #+#    #+#             */
/*   Updated: 2022/10/06 16:05:13 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
 #define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat : public WrongAnimal
{
	public:
		WrongCat(void);
		WrongCat(WrongCat const & src);
		~WrongCat(void);
		WrongCat & operator=(WrongCat const & rhs);

		void makeSound(void) const;

	protected:
		std::string type;
};

std::ostream & operator<<(std::ostream & o, WrongCat & i);

#endif
