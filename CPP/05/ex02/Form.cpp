/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 19:21:53 by aherrero          #+#    #+#             */
/*   Updated: 2022/11/05 15:58:58 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : name("Default"), _signed(false), grade(150), exec(1)
{
	if (this->grade > 150)
		throw GradeTooLowException();
	if (this->grade <= 0)
		throw GradeTooHighException();
}

Form::Form(std::string name, u_int16_t grade, u_int16_t exec) : name(name), _signed(false), grade(grade), exec(exec)
{
	if (this->grade > 150)
		throw GradeTooLowException();
	if (this->grade <= 0)
		throw GradeTooHighException();
}

Form::Form(Form const & src) : name(src.getName()), _signed(src._signed), grade(src.getGrade()), exec(src.exec)
{
	//*this = src;
}

Form::~Form()
{

}

std::string	Form::getName(void) const
{
	return (this->name);
}

u_int16_t	Form::getGrade(void) const
{
	return (this->grade);
}

u_int16_t	Form::getExec(void) const
{
	return (this->exec);
}

bool	Form::getSigned(void)
{
	return (this->_signed);
}

void	Form::beSigned(Bureaucrat &target)
{
	if (this->_signed)
		throw FormFirmedException();
	if (target.getGrade() <= this->grade)
		this->_signed = true;
	else
		throw GradeTooLowException();
}

std::ostream & operator<<(std::ostream & o, Form & i)
{
	o << i.getName() << ":" << std::endl << "	Required grade: " << i.getGrade() << std::endl << "	Signed: ";
	if (i.getSigned())
		std::cout << "true";
	else
		std::cout << "false";
	return (o);
}
