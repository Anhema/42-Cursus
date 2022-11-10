/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 19:28:10 by aherrero          #+#    #+#             */
/*   Updated: 2022/11/05 10:33:55 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): Form("ShrubberyCreationForm", 145, 137), target("Default")
{

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): Form("ShrubberyCreationForm", 145, 137), target(target)
{
	
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src)
{
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	if (this != &rhs)
	{
		ShrubberyCreationForm *newShr = new ShrubberyCreationForm(rhs.getName());
		return (*newShr);
	}
	return (*this);
}

std::string	ShrubberyCreationForm::GetTarget(void) const
{
	return (this->target);
}


std::string tree = "     ccee88oo\n  C8O8O8Q8PoOb o8oo\n dOB69QO8PdUOpugoO9bD\nCgggbU8OU qOp qOdoUOdcb\n    6OuU  /p u gcoUodpP\n      \\\\\\//  /douUP\n        \\\\\\////\n         |||/\\\n         |||\\/\n         |||||\n   .....//||||\\....";

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	try
	{
		if (executor.getGrade() > this->getExec())
			throw GradeTooLowException();
		std::string output_file;
		output_file = this->GetTarget().append("_shrubbery");
		std::ofstream ofs(output_file);
		ofs << tree;
		ofs.close();
		std::cout << executor.getName() << " executes " << this->getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::string	str = e.what();
		std::cout << this->getName() << " cannot executed by " << executor.getName() << " because " << executor.getName() << "s grade is too low" << std::endl;
	}
}

std::ostream & operator<<(std::ostream & o, ShrubberyCreationForm & i)
{
	o << "ShrubberyCreationForm: " << i.getName();
	return (o);
}
