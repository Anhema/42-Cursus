/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:17:39 by aherrero          #+#    #+#             */
/*   Updated: 2022/11/30 17:54:07 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

int main(void)
{
	srand (time(NULL));
	int		N = 20000;
	Span	sp = Span(N);

	std::cout << "Span { ";
	for (int i = 0; i < N; i++)
	{
		int	n = rand() % N;
		sp.addNumber(n);
		if (i < N - 1)
			std::cout << n << ", ";
		else
			std::cout << n << " }" << std::endl;
	}
	
	std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
}
