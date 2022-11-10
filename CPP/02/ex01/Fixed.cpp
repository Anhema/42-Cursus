/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:38:08 by aherrero          #+#    #+#             */
/*   Updated: 2022/09/21 18:30:40 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->i = 0;
	return;
}

Fixed::Fixed(int i)
{
	std::cout << "Int constructor called" << std::endl;
	setRawBits(i);
	return;
}

Fixed::Fixed(float i)
{
	std::cout << "Float constructor called" << std::endl;
	setRawBits(i);
	return;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

int	Fixed::toInt(void) const
{
	return (this->i >> Fixed::bits);
}

float	Fixed::toFloat(void) const
{
	return ((float)this->i / (float)(1 << Fixed::bits));
}

int	Fixed::getRawBits(void) const
{
	return (this->i);
}

void	Fixed::setRawBits(int const raw)
{
	this->i = raw << Fixed::bits;
	return ;
}

void	Fixed::setRawBits(float const raw)
{
	this->i = roundf(raw * (1 << Fixed::bits));
	return ;
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs)
		this->i = rhs.getRawBits();
	return (*this);
}

std::ostream & operator<<(std::ostream & o, Fixed const & i)
{
	o << i.toFloat();
	return (o);
}
