/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 19:21:44 by aherrero          #+#    #+#             */
/*   Updated: 2022/11/05 10:47:54 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::cout << std::endl;
	{
		std::cout << "-------------ShrubberyCreationForm-------------" << std::endl << std::endl;
		Bureaucrat 				authorized("Authorized_Bureaucrat", 1);
		Bureaucrat 				no_authorized("No_Authorized_Bureaucrat", 149);
		ShrubberyCreationForm	form("ShrubberyCreationForm");

		authorized.executeForm(form);
		no_authorized.executeForm(form);
	}
	{
		std::cout << std::endl << std::endl << "-------------RobotomyRequestForm-------------" << std::endl << std::endl;
		Bureaucrat 				authorized("Authorized_Bureaucrat", 1);
		Bureaucrat 				no_authorized("No_Authorized_Bureaucrat", 149);
		RobotomyRequestForm		form("RobotomyRequestForm");
		
		authorized.executeForm(form);
		no_authorized.executeForm(form);
	}
	{
		std::cout << std::endl << std::endl << "-------------PresidentialPardonForm-------------" << std::endl << std::endl;
		Bureaucrat 				authorized("Authorized_Bureaucrat", 1);
		Bureaucrat 				no_authorized("No_Authorized_Bureaucrat", 149);
		PresidentialPardonForm	form("PresidentialPardonForm");
		
		authorized.executeForm(form);
		no_authorized.executeForm(form);
	}
	{
		std::cout << std::endl << std::endl << "-------------Intern-------------" << std::endl << std::endl;
		{
			std::cout << std::endl << std::endl;
			Intern someRandomIntern;
			Form* rrf;
			Bureaucrat 				authorized("Authorized_Bureaucrat", 1);
			rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
			authorized.executeForm(*rrf);
		}
		{
			std::cout << std::endl << std::endl;
			Intern someRandomIntern;
			Form* rrf;
			Bureaucrat 				authorized("Authorized_Bureaucrat", 1);
			rrf = someRandomIntern.makeForm("robotomy request", "Bender");
			authorized.executeForm(*rrf);
		}
		{
			std::cout << std::endl << std::endl;
			Intern someRandomIntern;
			Form* rrf;
			Bureaucrat 				authorized("Authorized_Bureaucrat", 1);
			rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
			authorized.executeForm(*rrf);
		}
		{
			std::cout << std::endl << std::endl;
			Intern someRandomIntern;
			Form* rrf;
			Bureaucrat 				authorized("Authorized_Bureaucrat", 1);
			rrf = someRandomIntern.makeForm("shrubberycreation", "Bender");
			authorized.executeForm(*rrf);
		}
		{
			std::cout << std::endl << std::endl;
			Intern someRandomIntern;
			Form* rrf;
			Bureaucrat 				authorized("Authorized_Bureaucrat", 1);
			rrf = someRandomIntern.makeForm("test", "Bender");
			authorized.executeForm(*rrf);
		}
		{
			std::cout << std::endl << std::endl;
			Intern someRandomIntern;
			Form* rrf;
			Bureaucrat 				authorized("presidential pardon", 1);
			rrf = someRandomIntern.makeForm("Authorized_Bureaucrat", "Bender");
			authorized.executeForm(*rrf);
		}
	}
	std::cout << std::endl << std::endl;
	return (0);
}
