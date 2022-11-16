/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:05:33 by aherrero          #+#    #+#             */
/*   Updated: 2022/11/15 20:20:59 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	int random_integer = rand()%3;
	if (random_integer == 0)
	{
		std::cout << "A was created";
		return (new A());
	}
	if (random_integer == 1)
	{
		std::cout << "B was created";
		return (new B());
	}
	if (random_integer == 2)
	{
		std::cout << "C was created";
		return (new C());
	}
	return (NULL);
}

void identify(Base* p)
{
	if (!p)
		std::cout << "null" << std::endl;
	A	*a = dynamic_cast<A *>(p);
	if (a)
		std::cout << "A" << std::endl;
	B	*b = dynamic_cast<B *>(p);
	if (b)
		std::cout << "B" << std::endl;
	C	*c = dynamic_cast<C *>(p);
	if (c)
		std::cout << "C" << std::endl;
}

void identify(Base &p)
{

	try
	{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch(const std::exception& e)
	{
		try
		{
			B &b = dynamic_cast<B &>(p);
			(void)b;
			std::cout << "B" << std::endl;
		}
		catch(const std::exception& e)
		{
			try
			{
				C &c = dynamic_cast<C &>(p);
				(void)c;
				std::cout << "C" << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cout << "null" << std::endl;
			}
		}
	}

}

int main()
{

	srand (time(NULL));
	
	for (size_t i = 0; i < 20; i++)
	{
		Base *p;
		std::cout << "----------";
		p = generate();
		std::cout << "----------" << std::endl;
		identify(p);
		identify(*p);

		std::cout << std::endl;
		delete (p);
	}
	
	Base *p = NULL;
	Base *p2 = new Base();
	std::cout << "----------NULL----------" << std::endl;
	identify(p);
	identify(*p2);
	delete (p2);
	return (0);
}
