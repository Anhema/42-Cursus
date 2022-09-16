/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 18:40:46 by aherrero          #+#    #+#             */
/*   Updated: 2022/09/13 16:26:26 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
 #define WEAPON_HPP

#include <iostream>

class Weapon
{
	public:
		Weapon(std::string name);
		~Weapon(void);
		std::string getType(void);
		void setType(std::string name);

	private:
		std::string type;
};

#endif
