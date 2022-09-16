/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 18:09:12 by aherrero          #+#    #+#             */
/*   Updated: 2022/09/08 17:03:33 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contacts.hpp"

Contacts add_contact(Contacts contact)
{
	std::string str = "";
	std::string name = "";
	std::string last_name = "";
	std::string nickname = "";
	std::string	phone = "";
	std::string darkest_secret = "";
	int			i;

	//contact.create_contact("", "", "", "", "");
	std::cout << "name: ";
	std::cin >> name;
	std::cout << "last_name: ";
	std::cin >> last_name;
	std::cout << "nickname: ";
	std::cin >> nickname;
	std::cout << "phone: ";
	std::cin >> phone;
	i = 0;
	while (phone[i])
	{
		if (phone[i] < '0' || phone[i] > '9')
		{
			std::cout << "phone: ";
			std::cin >> phone;
			continue ;
		}
		i++;
	}
	std::cout << "darkest_secret: ";
	std::cin >> darkest_secret;
	contact.create_contact(name, last_name, nickname, phone, darkest_secret);
	return (contact);
}

void	print_phonebook(Contacts	contacts[8])
{
	int	i;
	int	n;
	std::string str;

	std::cout << "\x1B[2J\x1B[H";
	std::cout << "|   index  |first name|last name | nickname |" << std::endl;
	i = 0;
	while (i < 8)
	{
		contacts[i].show_contact(i);
		i++;
	}	
	std::cout << std::endl << "Type index to see all info or 0 to return..." << std::endl;
	std::cin >> n;
	if (n == 0 || n >= 8)
		return ;
	else
	{
		n--;
		contacts[n].show_full_contact();
	}
	while (1)
	{
		std::cout << std::endl << "Type 0 to return..." << std::endl;
		std::cin >> n;
		if (n == 0)
			return ;
	}
}

int main(void)
{
	std::string str;
	int			current_contact;
	int			show_contact;
	Contacts	contacts[8];

	current_contact = 0;
	show_contact = 0;
	while (1)
	{
		std::cout << "\x1B[2J\x1B[H";
		std::cout << std::endl << "Type 'ADD' to append new contact" << std::endl;
		std::cout << "Type 'SEARCH' to view contact list" << std::endl;
		std::cout << "Type 'EXIT' to close" << std::endl << std::endl;
		std::cout << ">> ";
		std::cin >> str;
		if (str == "EXIT")
			return (0);
		else if (str == "ADD")
		{
			contacts[current_contact] = add_contact(contacts[current_contact]);
			current_contact++;
			if (current_contact >= 8)
				current_contact = 0;
		}
		else if (str == "SEARCH")
			print_phonebook(contacts);
		str = "";
	}
	return (0);
}
