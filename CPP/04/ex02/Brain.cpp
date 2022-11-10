/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:10:31 by aherrero          #+#    #+#             */
/*   Updated: 2022/10/06 16:55:41 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(Brain const &src)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = src;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(Brain const &rhs)
{
	for (size_t i = 0; i < 100; i++)
	{
		this->ideas[i] = rhs.ideas[i];
	}
	return (*this);
}

std::ostream & operator<<(std::ostream & o, Brain & i)
{
	o << *(i.ideas);
	return (o);
}
