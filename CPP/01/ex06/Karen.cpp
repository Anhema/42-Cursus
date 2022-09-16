/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:19:55 by aherrero          #+#    #+#             */
/*   Updated: 2022/09/15 18:55:47 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

Karen::Karen(void)
{
	std::cout << "Constructor called" << std::endl << std::endl;
}

Karen::~Karen(void)
{
	std::cout << std::endl << "Destructor called" << std::endl;
}

void	Karen::debug(void)
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!. Me gustaría algo de bacon extra para mi hamburguesa 7XL-doble-queso-triple-pepinillo-ketchup-especial. Simplemente, me encanta." << std::endl;
}

void	Karen::info(void)
{
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!. No me puedo creer que añadir bacon extra cueste más dinero. No ponéis suficiente. Si lo hicierais no tendría que pedirlo." << std::endl;
}

void	Karen::warning(void)
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month.. Creo que me merezco algo más de bacon gratis. Llevo viniendo años y tú empezaste a trabajar aquí el mes pasado." << std::endl;
}

void	Karen::error(void)
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable, I want to speak to the manager now.. Esto es inaceptable. Quiero hablar con el responsable ahora mismo." << std::endl;
}

void	Karen::complain(std::string level)
{
	std::string levels_lst[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			i;
	int			value;

	i = 0;
	while (i < 4)
	{
		if (level == levels_lst[i])
			value = i;
		i++;
	}
	
	switch(value)
	{
		case 0: debug();
		case 1: info();
		case 2: warning();
		case 3: error(); break;
		default: std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
