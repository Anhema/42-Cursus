/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:09:32 by aherrero          #+#    #+#             */
/*   Updated: 2022/11/01 11:30:12 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
 #define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class ICharacater;

class Ice: public AMateria
{
	protected:
	
	public:
		Ice(void);
		Ice(std::string const & type);
		~Ice(void);

		Ice & operator=(const Ice & rhs);
		
		std::string const & getType() const;
		AMateria* clone() const;
		void use(ICharacter& target);
};

std::ostream & operator<<(std::ostream & o, Ice & i);

#endif
