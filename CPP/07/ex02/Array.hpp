/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:19:06 by aherrero          #+#    #+#             */
/*   Updated: 2022/11/22 17:39:07 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<typename T>
class Array
{
	public:
		
		Array<T> (void)
		{
			this->size = 0;
			this->content = NULL;
		}

		Array<T> (unsigned int n)
		{
			this->size = n;
			if (n < 0)
				throw std::overflow_error("Index out of bounds");
			this->content = new T[n];		
		}

		Array<T>(Array<T> const & src)
		{
			*this = src;
		}
		
		~Array<T>(void)
		{
			if (this->size > 0)
				delete [] this->content;
		}

		T & operator[](const int & index) const
		{
			if (index < 0 || index >= this->size)
				throw std::overflow_error("Index out of bounds");
			return (this->content[index]);
		}

		Array & operator=(const Array &rhs)
		{
			if (this != &rhs)
			{
				this->size = rhs.getSize();
				this->content = new T[this->size];
				for (int i = 0; i < this->size; i++)
				{
					this->content[i] = rhs[i];
				}
			}
			return (*this);
		}

		int	getSize(void) const
		{
			return (this->size);
		}
	
	private:

		T 		*content;
		int		size;
};

#endif
