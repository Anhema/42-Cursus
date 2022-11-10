/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:09:19 by aherrero          #+#    #+#             */
/*   Updated: 2022/11/05 15:07:54 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): Form("PresidentialPardonForm", 25, 5), target("Default")
{

}

PresidentialPardonForm::PresidentialPardonForm(std::string target): Form("PresidentialPardonForm", 25, 5), target(target)
{

}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src)
{
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	if (this != &rhs)
	{
		PresidentialPardonForm *newPre = new PresidentialPardonForm(rhs.getName());
		return (*newPre);
	}
	return (*this);
}

std::string	PresidentialPardonForm::GetTarget(void) const
{
	return (this->target);
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	try
	{
		if (this->GetTarget() == "")
			throw NotValidFormException();
		if (executor.getGrade() > this->getExec())
			throw GradeTooLowException();
		std::cout << this->GetTarget() << " has been pardoned by Zafod Beeblebrox" << std::endl;
	}
	catch(const NotValidFormException& e)
	{
		std::string	str = e.what();
		std::cout << str << std::endl;
	}
	catch(const std::exception& e)
	{
		std::string	str = e.what();
		std::cout << this->getName() << " cannot executed by " << executor.getName() << " because " << executor.getName() << "s grade is too low" << std::endl;
	}
}

std::ostream & operator<<(std::ostream & o, PresidentialPardonForm & i)
{
	o << "PresidentialPardonForm: " << i.getName();
	return (o);
}
