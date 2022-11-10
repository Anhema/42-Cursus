/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:58:46 by aherrero          #+#    #+#             */
/*   Updated: 2022/11/05 16:14:48 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << std::endl;
	{
		try
		{
			Form		form("Form", 0, 0);
			Bureaucrat	bure("Ander", 1);

			std::cout << form << std::endl;
			std::cout << bure << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "-----------------------" << std::endl << std::endl;
	{
		try
		{
			Form		form("Form", 151, 151);
			Bureaucrat	bure("Ander", 1);

			std::cout << form << std::endl;
			std::cout << bure << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "-----------------------" << std::endl << std::endl;
	{
		try
		{
			Form		form("Form", 1, 1);
			Bureaucrat	bure("Ander", 2);

			std::cout << form << std::endl;
			std::cout << bure << std::endl;
			std::cout << std::endl << bure.getName() << " try to firm " << form.getName() << ":" << std::endl;
			bure.signForm(form);
			std::cout << std::endl << bure.getName() << " try to execute " << form.getName() << ":" << std::endl;
			form.execute(bure);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "-----------------------" << std::endl << std::endl;
	{
		try
		{
			Form		form("Form", 1, 1);
			Form		form2("Form2", 10, 10);
			Bureaucrat	bure("Ander", 5);

			std::cout << form << std::endl;
			std::cout << form2 << std::endl;
			std::cout << bure << std::endl;
			
			std::cout << std::endl << bure.getName() << " try to firm " << form.getName() << ":" << std::endl;
			bure.signForm(form);
			std::cout << std::endl << bure.getName() << " try to execute " << form.getName() << ":" << std::endl;
			form.execute(bure);

			std::cout << std::endl << bure.getName() << " try to firm " << form2.getName() << ":" << std::endl;
			bure.signForm(form2);
			std::cout << std::endl << bure.getName() << " try to execute " << form.getName() << ":" << std::endl;
			form2.execute(bure);

			std::cout << std::endl;
			std::cout << form << std::endl;
			std::cout << form2 << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	return (0);
}
