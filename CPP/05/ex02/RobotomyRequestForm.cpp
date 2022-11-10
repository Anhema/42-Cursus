/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:05:47 by aherrero          #+#    #+#             */
/*   Updated: 2022/11/05 16:18:42 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): Form("RobotomyRequestForm", 72, 45), target("Default")
{

}

RobotomyRequestForm::RobotomyRequestForm(std::string target): Form("RobotomyRequestForm", 72, 45), target(target)
{

}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src)
{
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	if (this != &rhs)
	{
		RobotomyRequestForm *newRob = new RobotomyRequestForm(rhs.getName());
		return (*newRob);
	}
	return (*this);
}

std::string	RobotomyRequestForm::GetTarget(void) const
{
	return (this->target);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	try
	{
		if (executor.getGrade() > this->getExec())
			throw GradeTooLowException();
		int	n;
		srand((unsigned) time(0));
		n = rand() % 2;
		if (n == 0)
			std::cout << executor.getName() << " has been robotomized successfully" << std::endl;
		else
			throw RobotomizedException();
	}
	catch(const RobotomizedException& e)
	{
		std::string	str = e.what();
		std::cout << executor.getName() << " robotomization failure" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::string	str = e.what();
		std::cout << this->getName() << " cannot executed by " << executor.getName() << " because " << executor.getName() << "s grade is too low" << std::endl;
	}
}

std::ostream & operator<<(std::ostream & o, RobotomyRequestForm & i)
{
	o << "RobotomyRequestForm: " << i.getName();
	return (o);
}
