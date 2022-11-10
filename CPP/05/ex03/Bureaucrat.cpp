/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 19:22:01 by aherrero          #+#    #+#             */
/*   Updated: 2022/11/05 15:06:30 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name("Default"), grade(2)
{
	if (this->grade > 150)
		throw GradeTooLowException();
	if (this->grade <= 0)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(std::string name, u_int16_t grade) : name(name), grade(grade)
{
	if (this->grade > 150)
		throw GradeTooLowException();
	if (this->grade <= 0)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(Bureaucrat const & src)
{
	*this = src;
}

Bureaucrat::~Bureaucrat()
{

}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this != &rhs)
	{
		Bureaucrat *newBure = new Bureaucrat(rhs.getName(), rhs.grade);
		return (*newBure);
	}
	return (*this);
}

std::string	Bureaucrat::getName(void) const
{
	return (this->name);
}

u_int16_t	Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

void		Bureaucrat::increment(void)
{
	if ((this->grade - 1) <= 0)
		throw GradeTooHighException();
	this->grade--;	
}

void		Bureaucrat::decrement(void)
{
	if ((this->grade + 1) > 150)
		throw GradeTooLowException();
	this->grade++;
}

void	Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signs " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::string	str = e.what();
		if (str == "form already firmed")
			std::cout << this->getName() << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
		else
			std::cout << this->getName() << " cannot sign " << form.getName() << " because " << this->getName() << "s grade is too low" << std::endl;
	}
	
}

void	Bureaucrat::executeForm(Form const &form)
{
	try
	{
		form.execute(*this);
	}
	catch(const std::exception& e)
	{
		std::string	str = e.what();
		std::cout << this->getName() << " cannot execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream & operator<<(std::ostream & o, Bureaucrat & i)
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade();
	return (o);
}
