/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:13:36 by aherrero          #+#    #+#             */
/*   Updated: 2022/11/15 20:18:10 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int main(void)
{
	std::string str = "Hola Mundo";

	Data		*ptr =  new Data();
	ptr->data = str;
	std::cout << "Ptr: " << ptr << std::endl;
	
	uintptr_t	raw;
	raw = serialize(ptr);
	std::cout << "Raw: " << raw << std::endl;
	
	Data		*result;
	result = deserialize(raw);
	std::cout << "Result: " << result << std::endl;	
	std::cout << "Result_value: " << result->data << std::endl;
	if (ptr)
		delete (ptr);
	return (0);
}
