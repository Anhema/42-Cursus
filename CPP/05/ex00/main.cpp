/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:17:55 by aherrero          #+#    #+#             */
/*   Updated: 2022/11/01 20:30:55 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	std::cout << std::endl;
	{
		try
		{
			Bureaucrat test("First", 0);
			std::cout << test << std::endl;
			std::cout << "Try Increment: ";
			test.increment();
			std::cout << "Success" << std::endl;
			std::cout << test << std::endl;
		}
		catch(std::exception& e)
		{
			std::cout << e.what() << std::endl;;
		}
		
	}
	std::cout << std::endl << "-----------------------" << std::endl << std::endl;
	{
		try
		{
			Bureaucrat test("First", 151);
			std::cout << test << std::endl;
			std::cout << "Try Increment: ";
			test.increment();
			std::cout << "Success" << std::endl;
			std::cout << test << std::endl;
		}
		catch(std::exception& e)
		{
			std::cout << e.what() << std::endl;;
		}
		
	}
	std::cout << std::endl << "-----------------------" << std::endl << std::endl;
	{
		try
		{
			Bureaucrat test("First", 1);
			std::cout << test << std::endl;
			std::cout << "Try Increment: ";
			test.increment();
			std::cout << "Success" << std::endl;
			std::cout << test << std::endl;
		}
		catch(std::exception& e)
		{
			std::cout << e.what() << std::endl;;
		}
		
	}
	std::cout << std::endl << "-----------------------" << std::endl << std::endl;
	{
		try
		{
			Bureaucrat test("Second", 2);
			std::cout << test << std::endl;
			std::cout << "Try Increment: ";
			test.increment();
			std::cout << "Success" << std::endl;
			std::cout << test << std::endl;
		}
		catch(std::exception& e)
		{
			std::cout << e.what() << std::endl;;
		}
		
	}
	std::cout << std::endl << "-----------------------" << std::endl << std::endl;
	{
		try
		{
			Bureaucrat test("Third", 150);
			std::cout << test << std::endl;
			std::cout << "Try Decrement: ";
			test.decrement();
			std::cout << "Success" << std::endl;
			std::cout << test << std::endl;
		}
		catch(std::exception& e)
		{
			std::cout << e.what() << std::endl;;
		}
		
	}
	std::cout << std::endl << "-----------------------" << std::endl << std::endl;
	{
		try
		{
			Bureaucrat test("Fourth", 149);
			Bureaucrat test2(test);
			std::cout << test << std::endl;
			std::cout << "Try Decrement: ";
			test.decrement();
			std::cout << "Success" << std::endl;
			std::cout << test << std::endl;
		}
		catch(std::exception& e)
		{
			std::cout << e.what() << std::endl;;
		}		
	}
	std::cout << std::endl;
	return (0);
}
