/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 18:09:47 by aherrero          #+#    #+#             */
/*   Updated: 2022/09/08 16:45:40 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTS_HPP
 #define CONTACTS_HPP

#include <iostream>

class Contacts
{
	public:
		//Contacts(std::string name, std::string last_name, std::string nickname, int phone, std::string darkest_secret);
		Contacts(void);
		~Contacts(void);
		void	show_contact(int i);
		void	show_full_contact(void);
		void	create_contact(std::string name, std::string last_name, std::string nickname, std::string phone, std::string darkest_secret);
	
	private:
		std::string name;
		std::string last_name;
		std::string nickname;
		std::string	phone;
		std::string darkest_secret;
		
};

#endif
