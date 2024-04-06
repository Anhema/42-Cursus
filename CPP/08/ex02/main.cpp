/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:47:09 by aherrero          #+#    #+#             */
/*   Updated: 2022/11/30 18:24:38 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"

int main(void)
{
	srand (time(NULL));
	std::cout << std::boolalpha;
	
	{
		std::cout << std::endl << "----------Subject main----------" << std::endl << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);	
	}
	{
		std::cout << std::endl << "----------Own main----------" << std::endl << std::endl;
		int size = 20;
		MutantStack<int> mstack;
		
		std::cout << "MutantStack empty = " << mstack.empty() << std::endl;
		std::cout << "Numbers { ";
		for (int i = 0; i < size; i++)
		{
			int	n = rand() % size;
			mstack.push(n);
			if (i < size - 1)
				std::cout << n << ", ";
			else
				std::cout << n << " }" << std::endl;
		}
		
		std::cout << "MutantStack empty = " << mstack.empty() << std::endl;
		std::cout << "MutantStack top = " << mstack.top() << std::endl;
		std::cout << "MutantStack size = " << mstack.size() << std::endl;
		std::cout << std::endl;
		
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		std::cout << "MutantStack { ";
		while (it != ite)
		{
			std::cout << *it;
			++it;
			if (it != ite)
				std::cout << ", ";
		}
		std::cout << " }" << std::endl;
		
		std::cout << std::endl << "POP (): remove " << size / 2 << " numbers" << std::endl << std::endl;
		for (int i = 0; i < size / 2; i++)
		{
			mstack.pop();
		}

		MutantStack<int>::iterator it2 = mstack.begin();
		MutantStack<int>::iterator ite2 = mstack.end();
		++it2;
		--it2;
		std::cout << "MutantStack { ";
		while (it2 != ite2)
		{
			std::cout << *it2;
			++it2;
			if (it2 != ite2)
				std::cout << ", ";
		}
		std::cout << " }" << std::endl;
	}
	return 0;
}
