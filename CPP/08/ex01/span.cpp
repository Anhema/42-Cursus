/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:17:52 by aherrero          #+#    #+#             */
/*   Updated: 2022/11/30 17:53:06 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span(unsigned int n)
{
	this->max = n;
}

Span::Span(Span const &n)
{
	*this = n;
}

Span::~Span(void)
{
}

Span &Span::operator=(const Span &src)
{
	this->max = src.max;
	std::vector<int> *Newnumbers = new std::vector<int> (src.numbers);
	this->numbers = *Newnumbers;
	return (*this);
}

void Span::addNumber(int n)
{
	try
	{
		if (this->numbers.size() < this->max)
			this->numbers.push_back(n);
		else
			throw std::exception();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Numbers are full" << std::endl;
	}
}

int Span::get_first(void)
{
	return (this->numbers.front());
}

int Span::shortestSpan(void)
{
	int	i = 0;
	
	std::vector<int> *new_numbers = new std::vector<int> (this->numbers);
	std::sort(new_numbers->begin(), new_numbers->end());
	i = new_numbers->front();
	delete (new_numbers);
	return (i);
}

int Span::longestSpan(void)
{
	int	i = 0;

	std::vector<int> *new_numbers =  new std::vector<int> (this->numbers);
	std::sort(new_numbers->begin(), new_numbers->end());
	i = new_numbers->back();
	delete(new_numbers);
	return (i);
}

std::ostream & operator<<(std::ostream & o, Span & i)
{
	o << i.get_first();
	return (o);
}
