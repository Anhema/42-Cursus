/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:37:23 by aherrero          #+#    #+#             */
/*   Updated: 2022/11/05 15:07:14 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <map>

Intern::Intern(void)
{

}

Intern::Intern(Intern const & src)
{
	*this = src;
}

Intern::~Intern()
{

}

Intern &Intern::operator=(const Intern &rhs)
{
	if (this != &rhs)
	{
		Intern *newInter = new Intern();
		return (*newInter);
	}
	return (*this);
}

Form	*Intern::makeForm(std::string form, std::string name)
{
	std::string levels_lst[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	int			i;
	int			value = -1;

	i = 0;
	while (i < 4)
	{
		if (form == levels_lst[i])
			value = i;
		i++;
	}

	switch (value)
	{
		case 0:
			std::cout << "Intern creates " << form << std::endl;
			return (new ShrubberyCreationForm(name));
		case 1:
			std::cout << "Intern creates " << form << std::endl;
			return (new RobotomyRequestForm(name));
		case 2:
			std::cout << "Intern creates " << form << std::endl;
			return (new PresidentialPardonForm(name));
		default:
			return (new PresidentialPardonForm(""));
	}
	return (NULL);
}

std::ostream & operator<<(std::ostream & o, Intern & i)
{
	(void)i;
	o << "Intern";
	return (o);
}
