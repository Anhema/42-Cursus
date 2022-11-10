/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:33:10 by aherrero          #+#    #+#             */
/*   Updated: 2022/11/01 11:36:26 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
 #define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string type;
	
	public:
		AMateria(void);
		AMateria(std::string const & type);
		AMateria(AMateria const & src);
		virtual ~AMateria(void);

		AMateria & operator=(const AMateria & rhs);
				
		virtual AMateria* clone() const = 0;
		std::string const & getType() const;
		virtual void use(ICharacter& target);
};

std::ostream & operator<<(std::ostream & o, AMateria & i);

#endif
