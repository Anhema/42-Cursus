/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 19:21:44 by aherrero          #+#    #+#             */
/*   Updated: 2022/11/04 18:18:33 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
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
	std::cout << std::endl << std::endl;
	return (0);
}
