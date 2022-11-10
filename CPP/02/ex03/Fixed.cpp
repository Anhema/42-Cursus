/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:38:08 by aherrero          #+#    #+#             */
/*   Updated: 2022/09/22 18:02:13 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	//std::cout << "Default constructor called" << std::endl;
	this->i = 0;
	return;
}

Fixed::Fixed(int i)
{
	//std::cout << "Int constructor called" << std::endl;
	setRawBits((int)i);
	return;
}

Fixed::Fixed(float i)
{
	//std::cout << "Float constructor called" << std::endl;
	setRawBits(i);
	return;
}

Fixed::Fixed(const Fixed &src)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

Fixed::~Fixed(void)
{
	//std::cout << "Destructor called" << std::endl;
	return;
}

int	Fixed::toInt(void) const
{
	return (this->i  >> Fixed::bits);
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
	//std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs)
		this->i = rhs.getRawBits();
	return (*this);
}

Fixed Fixed::operator+(const Fixed &rhs)
{
	//std::cout << "Sum operator called" << std::endl;
	Fixed a;
	a.setRawBits(toFloat() + rhs.toFloat());
	return (a);
}

Fixed Fixed::operator-(const Fixed &rhs)
{
	//std::cout << "Sub operator called" << std::endl;
	Fixed a;
	a.setRawBits(toFloat() - rhs.toFloat());
	return (a);
}

Fixed Fixed::operator*(const Fixed &rhs)
{
	//std::cout << "Mult operator called" << std::endl;
	Fixed a;
	a.setRawBits(toFloat() * rhs.toFloat());
	return (a);
}

Fixed Fixed::operator/(const Fixed &rhs)
{
	//std::cout << "Div operator called" << std::endl;
	Fixed a;
	a.setRawBits(toFloat() / rhs.toFloat());
	return (a);
}

bool Fixed::operator<(Fixed const &rhs) const
{
	//std::cout << "< operator called" << std::endl;
	if (this->getRawBits() < rhs.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator>(Fixed const &rhs) const
{
	//std::cout << "> operator called" << std::endl;
	if (this->getRawBits() > rhs.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed &rhs) const
{
	//std::cout << "<= operator called" << std::endl;
	if (this->getRawBits() <= rhs.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator>=(const Fixed &rhs) const
{
	//std::cout << ">= operator called" << std::endl;
	if (this->getRawBits() >= rhs.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator==(const Fixed &rhs) const
{
	//std::cout << "== operator called" << std::endl;
	if (this->getRawBits() == rhs.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed &rhs) const
{
	//std::cout << "!= operator called" << std::endl;
	if (this->getRawBits() != rhs.getRawBits())
		return (true);
	return (false);
}

Fixed Fixed::operator++(void)
{
	this->i++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	//std::cout << "Inc operator called" << std::endl;
	Fixed _result(*this);
	operator++();
	return (_result);
}

Fixed Fixed::operator--(void)
{
	this->i--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	//std::cout << "Inc operator called" << std::endl;
	Fixed _result(*this);
	operator--();
	return (_result);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (b);
	return (a);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a < b)
		return (b);
	return (a);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed &max(Fixed &a, Fixed &b)
{
	return (Fixed::max(a, b));
}

const Fixed &max(const Fixed &a, const Fixed &b)
{
	return (Fixed::max(a, b));
}

const Fixed &min(const Fixed &a, const Fixed &b)
{
	return (Fixed::min(a, b));
}

Fixed &min(Fixed &a, Fixed &b)
{
	return (Fixed::min(a, b));
}

std::ostream & operator<<(std::ostream & o, Fixed const & i)
{
	o << i.toFloat();
	return (o);
}


