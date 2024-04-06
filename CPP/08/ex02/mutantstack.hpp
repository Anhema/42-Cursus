/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:47:26 by aherrero          #+#    #+#             */
/*   Updated: 2022/11/30 18:03:31 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	private:

	public:
		MutantStack(){};
		MutantStack(MutantStack const & src)
		{
			*this = src;
		};
		~MutantStack(){};

		MutantStack &operator=(const MutantStack &rhc)
		{
			return (rhc);
		}
		
		typedef typename MutantStack<T>::container_type::iterator	iterator;
		
		iterator begin()
		{ 
			return this->c.begin(); 
		}
		
		iterator end()
		{
			return this->c.end();
		}
};

#endif
