/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:03:14 by aherrero          #+#    #+#             */
/*   Updated: 2022/11/05 16:08:54 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : name("Default"), _signed(false), exec(150), grade(150)
{
	if (this->grade > 150)
		throw GradeTooLowException();
	if (this->grade <= 0)
		throw GradeTooHighException();
}

Form::Form(std::string name, u_int16_t grade, u_int16_t exec) : name(name), _signed(false), exec(exec), grade(grade)
{
	if (this->grade > 150)
		throw GradeTooLowException();
	if (this->grade <= 0)
		throw GradeTooHighException();
}

Form::Form(Form const & src) : name(src.getName()), _signed(src._signed), exec(src.exec), grade(src.getGrade())
{
	*this = src;
}

Form::~Form()
{

}

Form &Form::operator=(const Form &rhs)
{
	if (this != &rhs)
	{
		Form *newForm = new Form(rhs.getName(), rhs.getGrade(), rhs.getExec());
		newForm->_signed = rhs._signed;
		return (*newForm);
	}
	return (*this);
}

std::string	Form::getName(void) const
{
	return (this->name);
}

u_int16_t	Form::getGrade(void) const
{
	return (this->grade);
}

bool	Form::getSigned(void)
{
	return (this->_signed);
}

u_int16_t	Form::getExec(void) const
{
	return (this->exec);
}

void	Form::execute(Bureaucrat const &executor) const
{
	try
	{
		if (executor.getGrade() > this->getExec())
			throw GradeTooLowException();
		std::cout << executor.getName() << " executes " << this->getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::string	str = e.what();
		std::cout << this->getName() << " cannot executed by " << executor.getName() << " because " << executor.getName() << "s grade is too low" << std::endl;
	}
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
	o << i.getName() << ":" << std::endl << "	Required grade: " << i.getGrade() << std::endl << "	Required execution: " << i.getExec() << std::endl << "	Signed: ";
	if (i.getSigned())
		std::cout << "true";
	else
		std::cout << "false";
	return (o);
}
