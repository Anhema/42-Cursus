/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:59:41 by aherrero          #+#    #+#             */
/*   Updated: 2022/10/22 12:06:07 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character: public ICharacter
{
	private:
		std::string name;
		AMateria	*inventory[4];
	
	public:
		Character(void);
		Character(std::string name);
		Character(Character const & src);
		~Character(void);

		Character & operator=(const Character & rhs);
		
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

std::ostream & operator<<(std::ostream & o, Character & i);

#endif
