/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:20:11 by aherrero          #+#    #+#             */
/*   Updated: 2022/10/07 18:50:54 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "Cat constructor called" << std::endl;
	this->brain = new Brain();
	this->type = "Cat";
}

Cat::Cat(const Cat &src)
{
	std::cout << "Cat deep copy constructor called" << std::endl;
	Cat *new_cat = new Cat();
	new_cat->brain = src.brain;
	new_cat->type = src.type;
	*this = *(new_cat);
	return;
}

Cat::~Cat(void)
{
	delete(this->brain);
	std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &rhs)
{
	if (this != &rhs)
	{
		Cat *new_cat = new Cat();
		new_cat->brain = rhs.brain;
		new_cat->type = rhs.type;
		*this = *(new_cat);
	}
	return (*this);
}

std::ostream & operator<<(std::ostream & o, Cat & i)
{
	o << i.getType();
	return (o);
}

std::string Cat::getType() const
{
	return(this->type);
}

void	Cat::makeSound(void)
{
	std::cout << this->type << " make sound (MEOW!!)" << std::endl;
}

Brain	*Cat::get_brain(void) const
{
	return (this->brain);
}
