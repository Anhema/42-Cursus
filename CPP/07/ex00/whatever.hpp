/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:19:41 by aherrero          #+#    #+#             */
/*   Updated: 2022/11/16 18:21:49 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template<typename T>
const T &max(T &x, T &y)
{
	if (x > y)
		return (x);
	else
		return (y);
}

template<typename T>
const T &min(T &x, T &y)
{
	if (x < y)
		return (x);
	else
		return (y);
}

template<typename T>
void swap(T &x, T &y)
{
	T  aux;

	aux = x;
	x = y;
	y = aux;
}

#endif
