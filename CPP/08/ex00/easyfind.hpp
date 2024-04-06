/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:20:55 by aherrero          #+#    #+#             */
/*   Updated: 2022/11/26 10:45:18 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

template<typename T>
void	easyfind(T t, int i)
{
	if (std::find(t.begin(), t.end(), i) == std::end(t))
		throw std::exception();
}

#endif
