/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:18:00 by aherrero          #+#    #+#             */
/*   Updated: 2022/11/30 17:46:19 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

class Span
{
	private:
		std::vector<int>	numbers;
		unsigned int		max;

	public:
		Span(unsigned int n);
		Span(Span const &n);
		~Span();

		Span &operator=(const Span &src);

		void addNumber(int n);
		int shortestSpan(void);
		int longestSpan(void);
		int get_first(void);
};

std::ostream & operator<<(std::ostream & o, Span & i);

#endif
