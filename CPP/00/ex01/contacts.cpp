/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:12:14 by aherrero          #+#    #+#             */
/*   Updated: 2022/09/08 16:56:51 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contacts.hpp"

Contacts::Contacts(void)
{
	return ;	
}
Contacts::~Contacts(void)
{
	return ;
}

void	print(std::string str)
{
	int	i;

	i = 0;
	while (i <= 9)
	{
		if (str[i] && str[i + 1] && i == 9)
			std::cout << ".";
		else if (str[i])
			std::cout << str[i];
		else
		{
			while (i <= 9)
			{
				std::cout << " ";
				i++;
			}
			break ;
		}
		i++;
	}	
}

void	Contacts::show_contact(int i)
{
	if (this->name == "")
		return ;
	std::cout << "|    " << (i + 1) << "     |";
	print(this->name);
	std::cout << "|";
	print(this->last_name);
	std::cout << "|";
	print(this->nickname);
	std::cout << "|" << std::endl;
}

void	Contacts::show_full_contact(void)
{
	if (this->name == "")
		return ;
	std::cout << std::endl;
	std::cout << "name:" << std::endl << this->name << std::endl;
	std::cout << "last_name:" << std::endl << this->last_name << std::endl;
	std::cout << "nickname:" << std::endl << this->nickname << std::endl;
	std::cout << "phone:" << std::endl << this->phone << std::endl;
	std::cout << "darkest_secret:" << std::endl << this->darkest_secret << std::endl;
}

void	Contacts::create_contact(std::string name, std::string last_name, std::string nickname, std::string phone, std::string darkest_secret)
{
	// if (this->name == "")
	// {
	// 	this->name = name;
	// 	this->last_name = last_name;
	// 	this->nickname = nickname;
	// 	this->phone = phone;
	// 	this->darkest_secret = darkest_secret;	
	// }
	// else
	// {
	// }
	this->name.replace(0, this->name.length(), name);
	this->last_name.replace(0, this->last_name.length(), last_name);
	this->nickname.replace(0, this->nickname.length(), nickname);
	this->phone.replace(0, this->phone.length(), phone);
	this->darkest_secret.replace(0, this->darkest_secret.length(), darkest_secret);
}
