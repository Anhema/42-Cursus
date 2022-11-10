/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:20:11 by aherrero          #+#    #+#             */
/*   Updated: 2022/10/06 16:15:10 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "Cat constructor called" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat &src)
{
	*this = src;
	return;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &rhs)
{
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

std::ostream & operator<<(std::ostream & o, Cat & i)
{
	o << i.getType();
	return (o);
}

void	Cat::makeSound(void) const
{
	std::cout << this->type << " make sound (MEOW!!)" << std::endl;
}
