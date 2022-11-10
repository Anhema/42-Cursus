/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:05:49 by aherrero          #+#    #+#             */
/*   Updated: 2022/10/22 13:38:34 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
 #define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*known[4];
	public:
		MateriaSource();
		~MateriaSource();
		void learnMateria(AMateria *learn);
		AMateria* createMateria(std::string const & type);
};

#endif
