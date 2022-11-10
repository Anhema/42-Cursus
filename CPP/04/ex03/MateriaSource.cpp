/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:37:08 by aherrero          #+#    #+#             */
/*   Updated: 2022/11/01 11:38:18 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

MateriaSource::MateriaSource()
{
	//std::cout << "MateriaSource Constructor called" << std::endl;
	for (size_t i = 0; i < 4; i++)
		this->known[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	//std::cout << "MateriaSource destructor called" << std::endl;
	for (size_t i = 0; i < 4; i++)
	{
		if (this->known[i] != NULL)
			delete (this->known[i]);
	}
}

void MateriaSource::learnMateria(AMateria *learn)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (this->known[i] == NULL)
		{
			this->known[i] = learn;
			//std::cout << learn->getType() << " learned" << std::endl;
			return;
		}
	}
	std::cout << "Already learned 4 Materias"<< std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	if (type == "ice")
	{
		Ice *new_materia = new Ice(type);
		return (new_materia);
	}
	else
	{
		Cure *new_materia = new Cure(type);
		return (new_materia);
	}
	return (NULL);
}
