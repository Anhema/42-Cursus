/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:11:09 by aherrero          #+#    #+#             */
/*   Updated: 2022/11/01 11:30:19 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
 #define CURE_HPP

#include "AMateria.hpp"

class Cure: public AMateria
{
	protected:
	
	public:
		Cure(void);
		Cure(std::string const & type);
		~Cure(void);

		Cure & operator=(const Cure & rhs);
		
		std::string const & getType() const;
		AMateria* clone() const;
		void use(ICharacter& target);
};

std::ostream & operator<<(std::ostream & o, Cure & i);

#endif
