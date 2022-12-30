/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:11:15 by aherrero          #+#    #+#             */
/*   Updated: 2022/12/30 14:05:51 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>
#include <algorithm>
#include <iterator>
#include <cstddef>
#include "ft_containers.hpp"


namespace ft
{
	template< class T, class Allocator = std::allocator<T> >
	class Vector
	{
		private:
			size_t				_size;
			size_t				_capacity;
			std::ptrdiff_t		_maxSize;
			T					*content;
			std::allocator<T>	alloc;

		public:

			// empty container constructor (default constructor)
			explicit Vector (const Allocator& alloc = Allocator())
			{
				this->_maxSize = std::numeric_limits<ptrdiff_t>::max();
				this->alloc = alloc;
				this->_size = 0;
				this->_capacity = 0;
			};

			// fill constructor
			explicit Vector (size_t n, const T& val = T(), const Allocator& alloc = Allocator())
			{
				this->_maxSize = std::numeric_limits<ptrdiff_t>::max();
				this->alloc = alloc;
				this->content = this->alloc.allocate(n);
				for (size_t i = 0; i < n; i++)
				{
					this->content[i] = val;
				}
				this->_size = n;
				this->_capacity = n;
			};

			// range constructor
			//typename ft::enable_if<std::is_pointer<InputIterator>::value, bool>::type
			template <class InputIterator>
			Vector (InputIterator first, InputIterator last, const Allocator& alloc = Allocator(), typename ft::enable_if<!std::is_integral<InputIterator>::value>::type* = 0)
			{
				this->_maxSize = std::numeric_limits<ptrdiff_t>::max();
				this->alloc = alloc;
				size_t n = 0;
				InputIterator tmp = first;
				while (tmp != last)
				{
					n++;
					tmp++;
				}
				this->content = this->alloc.allocate(n);
				for (size_t i = 0; i < n; i++)
				{
					this->content[i] = *first;
					first++;
				}
				this->_capacity = n;
				this->_size = n;
			};

			// copy constructor
			Vector (const Vector& x)
			{
				this->_maxSize = std::numeric_limits<ptrdiff_t>::max();
				*this = x;
				this->_size = 0;
				this->_capacity = 0;
			};

			// destructor
			~Vector()
			{
				// for (size_t i = 0; i < this->size(); i++)
				// {
				// 	//T *elem = std::addressof(this->content[i]);
				// 	this->content[i]->~T();
				// 	//std::destroy_at(this->content[i]);
				// }
				if (this->_capacity > 0)
					this->alloc.deallocate(this->content, this->_capacity);
			};

			Vector& operator= (const Vector& x)
			{
				while (this->size() > 0)
				{
					this->pop_back();
				}
				
				Vector<int>::iterator ite = x.end();
				for (Vector<int>::iterator it = x.begin(); it != ite; it++)
				{
					this->push_back(*it);
				}

				this->_capacity = x.capacity();
				this->_size = x.size();
				return (*this);
			};

			//Iterators
			
			typedef typename ft::iterator<T> 	iterator;
			typedef typename ft::r_iterator<T> 	reverse_iterator;

			reverse_iterator rend()
			{	
				return (&content[0]);
			};

			reverse_iterator rbegin()
			{	
				return (&content[this->size() - 1]);
			};

			iterator begin() const
			{
				return (&content[0]);
			}

			iterator end() const
			{
				return (&content[this->size()]);
			}

			//Capacity
			size_t size() const
			{
				return (this->_size);
			};

			size_t max_size() const
			{
				return sizeof(T) == 1 ? this->_maxSize : (this->_maxSize / (sizeof(T) / 2));
			};

			size_t capacity() const
			{
				return (this->_capacity);
			};

			bool empty() const
			{
				if (this->size() == 0)
					return (true);
				return (false);
			};

			void reserve (size_t n)
			{
				if (n <= this->capacity())
					return ;
				if (this->capacity() > 0)
				{
					T	*new_vector;
					new_vector = this->alloc.allocate(this->_size + n);
					for (size_t i = 0; i < this->size(); i++)
					{
						new_vector[i] = this->content[i];
					}
					this->alloc.deallocate(this->content, this->_capacity);
					this->content = new_vector;
				}
				else
					this->content = this->alloc.allocate(n);
				this->_capacity = n;
			};

			void resize (size_t n, T val = T())
			{
				if (n <= this->size())
				{
					//this->alloc.deallocate(this->content, this->_capacity);
					this->_size = n;
					for (size_t i = 0; i < this->size(); i++)
					{
						if (val)
							this->content[i] = val;
					}
				}
				else
				{
					if (this->capacity() < n)
						this->reserve(n);
					this->_size = n;
					for (size_t i = 0; i < this->size(); i++)
					{
						if (val || !this->content[i])
							this->content[i] = val;
					}
				}
			};
			
			// Element access
			T &operator[](size_t & index)
			{
				if (index < 0 || index >= this->size())
					throw std::overflow_error("Index out of bounds");

				return (this->content[index]);
			};
			
			const T &operator[](size_t index) const
			{
				if (index < 0 || index >= this->size())
					throw std::overflow_error("Index out of bounds");

				return (this->content[index]);
			};

			T  &at(size_t n)
			{
				if (this->size() == 0)
					throw std::overflow_error("undefined behavior");
				return (this->content[n]);
			};
			
			const T  &at(size_t n) const
			{
				if (this->size() == 0)
					throw std::overflow_error("undefined behavior");
				return (this->content[n]);
			};
			
			T  &front(void)
			{
				if (this->size() <= 0)
					throw std::overflow_error("undefined behavior");
				return (this->content[0]);
			};
			
			const T  &front(void) const
			{
				if (this->size() == 0)
					throw std::overflow_error("undefined behavior");
				return (this->content[0]);
			};

			T  &back(void)
			{
				if (this->size() == 0)
					throw std::overflow_error("undefined behavior");
				return (this->content[this->size() - 1]);
			};
			
			const T  &back(void) const
			{
				if (this->size() == 0)
					throw std::overflow_error("undefined behavior");
				return (this->content[this->size() - 1]);
			};

			//Modifiers
			void push_back(const T& n)
			{
				if (this->capacity() > 0)
				{
					if (this->size() == this->capacity())
						this->_capacity *= 2;	
					this->_size++;
					T	*new_vector;
					new_vector = this->alloc.allocate(this->_size);
					for (size_t i = 0; i < this->size() - 1; i++)
					{
						new_vector[i] = this->content[i];
					}
					new_vector[this->size() - 1] = n;
					this->alloc.deallocate(this->content, this->_capacity);
					this->content = new_vector;
				}
				else
				{
					this->_size = 1;
					if (this->capacity() == 0)
						this->_capacity = 1;
					this->content = this->alloc.allocate(1);
					this->content[0] = n;					
				}
			};

			void pop_back()
			{
				if (this->size() <= 0)
					throw std::overflow_error("undefined behavior");
				this->_size--;
				T	*new_vector;
				new_vector = this->alloc.allocate(this->_size);
				for (size_t i = 0; i < this->size(); i++)
				{
					new_vector[i] = this->content[i];
				}
				this->alloc.deallocate(this->content, this->_size);
				this->content = new_vector;
			};

			template <class InputIterator>  void assign (InputIterator first, InputIterator last, typename ft::enable_if<!std::is_integral<InputIterator>::value>::type* = 0)
			{
				this->alloc.deallocate(this->content, this->_capacity);
				size_t n = 0;
				InputIterator tmp = first;
				while (tmp != last)
				{
					n++;
					tmp++;
				}
				this->content = this->alloc.allocate(n);
				for (size_t i = 0; i < n; i++)
				{
					this->content[i] = *first;
					first++;
				}
				this->_capacity = n;
				this->_size = n;
			};
			
			void assign (size_t n, const T& val)
			{
				this->alloc.deallocate(this->content, this->_capacity);
				this->content = this->alloc.allocate(n);
				for (size_t i = 0; i < n; i++)
				{
					this->content[i] = val;
				}
				this->_size = n;
				this->_capacity = n;
			};

			iterator insert (iterator position, const T& val)
			{
				(void) val;
				(void) position;
			};

			void insert (iterator position, size_t n, const T& val)
			{
				(void) position;
				(void) n;
				(void) val;
			};

			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!std::is_integral<InputIterator>::value>::type* = 0)
			{
				(void) first;
				(void) last;
				(void) position;
			};

			iterator erase (iterator position)
			{
				(void) position;
			};
			
			iterator erase (iterator first, iterator last)
			{
				(void) first;
				(void) last;
			};

			void swap (Vector& x)
			{
				(void) x;
			};

			void clear()
			{
				
			};

			// Allocator
			Allocator get_allocator() const
			{
				return (alloc);
			}
	};
}

#endif
