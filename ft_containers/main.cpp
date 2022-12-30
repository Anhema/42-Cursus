/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:29:36 by aherrero          #+#    #+#             */
/*   Updated: 2022/12/30 13:58:23 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <memory>
#include "Vector.hpp"

using namespace ft;

int main()
{

	try
	{
		{
			std::cout << "----------" << std::endl;
			Vector<long double> v;
			std::vector<long double> v2;
			std::cout << "v.size() = " << v.size() << std::endl;
			std::cout << std::endl;
			// std::cout << "front = " << v.front() << std::endl;
			// std::cout << "back = " << v.back() << std::endl;
			// std::cout << "at(3) = " << v.at(3) << std::endl;
			for (size_t i = 0; i < 10; i++)
			{
				v.push_back(i);
			}
			std::cout << "----------" << std::endl;
			for (size_t i = 0; i < v.size(); i++)
			{
				std::cout << i << " -- ";
				std::cout << v[i] << std::endl;
			}
			std::cout << std::endl;
			std::cout << "Max Size V= " << v.max_size() << std::endl;
			std::cout << "Max Size V2 = " << v2.max_size() << std::endl;
			std::cout << "front = " << v.front() << std::endl;
			std::cout << "back = " << v.back() << std::endl;
			std::cout << "at(3) = " << v.at(3) << std::endl;
			std::cout << "----------" << std::endl;
			v.pop_back();
			for (size_t i = 0; i < v.size(); i++)
			{
				std::cout << i << " -- ";
				std::cout << v[i] << std::endl;
			}
					std::cout << std::endl;
			std::cout << "front = " << v.front() << std::endl;
			std::cout << "back = " << v.back() << std::endl;
			std::cout << "at(3) = " << v.at(3) << std::endl;
			std::cout << "----------" << std::endl;
			v.at(3) = 42;
			for (size_t i = 0; i < v.size(); i++)
			{
				std::cout << i << " -- ";
				std::cout << v[i] << std::endl;
			}
			std::cout << std::endl;
			std::cout << "front = " << v.front() << std::endl;
			std::cout << "back = " << v.back() << std::endl;
			std::cout << "at(3) = " << v.at(3) << std::endl;
		}
		{
			std::cout << "----------EXCEPTIONS----------" << std::endl;
			Vector<int> v;
			std::cout << "size = " << v.size() << std::endl;
			try
			{
				std::cout << "front = " << v.front() << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
			try
			{
				std::cout << "back = " << v.back() << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
			try
			{
				std::cout << "at(3) = " << v.at(3) << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
			try
			{
				std::cout << "pop_back() = ";
				v.pop_back();
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}
		{
			std::cout << "----------ITERATORS----------" << std::endl;
			Vector<int> v;
			Vector<int> tmp(1000, 4);
			for (size_t i = 0; i <= 10; i++)
			{
				v.push_back(i + 1);
			}
			std::cout << std::endl;
			std::cout << "front = " << v.front() << std::endl;
			std::cout << "back = " << v.back() << std::endl;
			std::cout << "at(3) = " << v.at(3) << std::endl;
			Vector<int>::iterator ite = v.end();
			for (Vector<int>::iterator it = v.begin(); it != ite; it++)
			{
				std::cout << *it << std::endl;
			}
			std::cout << "----------" << std::endl;
			Vector<int> v2(v.begin(), v.end());
			for (size_t i = 0; i < v2.size(); i++)
			{
				std::cout << v2[i] << std::endl;
			}
			std::cout << "----------" << std::endl;
		}
		{
			std::cout << "----------RESERVE----------" << std::endl;
			std::vector<int> _v(10, 4);
			Vector<int> v(10, 4);
			{
				Vector<int>::iterator ite = v.end();
				for (Vector<int>::iterator it = v.begin(); it != ite; it++)
				{
					std::cout << *it << std::endl;
				}
				std::cout << "----------" << std::endl;
				std::vector<int>::iterator _ite = _v.end();
				for (std::vector<int>::iterator _it = _v.begin(); _it != _ite; _it++)
				{
					std::cout << *_it << std::endl;
				}	
			}
			std::cout << "STD vector(10, 4) capacity = " << _v.capacity() << std::endl;
			std::cout << "STD vector(10, 4) size = " << _v.size() << std::endl;
			std::cout << "STD vector(10, 4) max_size = " << _v.max_size() << std::endl;
			std::cout << "FT vector(10, 4) capacity = " << v.capacity() << std::endl;
			std::cout << "FT vector(10, 4) size = " << v.size() << std::endl;
			std::cout << "FT vector(10, 4) max_size = " << v.max_size() << std::endl;
			std::cout << "----------" << std::endl;
			_v.reserve(15);
			v.reserve(15);
			{
				Vector<int>::iterator ite = v.end();
				for (Vector<int>::iterator it = v.begin(); it != ite; it++)
				{
					std::cout << *it << std::endl;
				}
				std::cout << "----------" << std::endl;
				std::vector<int>::iterator _ite = _v.end();
				for (std::vector<int>::iterator _it = _v.begin(); _it != _ite; _it++)
				{
					std::cout << *_it << std::endl;
				}	
			}
			std::cout << "STD vector(10, 4) capacity = " << _v.capacity() << std::endl;
			std::cout << "STD vector(10, 4) size = " << _v.size() << std::endl;
			std::cout << "STD vector(10, 4) max_size = " << _v.max_size() << std::endl;
			std::cout << "FT vector(10, 4) capacity = " << v.capacity() << std::endl;
			std::cout << "FT vector(10, 4) size = " << v.size() << std::endl;
			std::cout << "FT vector(10, 4) max_size = " << v.max_size() << std::endl;
		}
		{
			std::cout << "----------RESIZE----------" << std::endl;
			std::vector<int> _v(10, 4);
			Vector<int> v(10, 4);
			{
				Vector<int>::iterator ite = v.end();
				for (Vector<int>::iterator it = v.begin(); it != ite; it++)
				{
					std::cout << *it << std::endl;
				}
				std::cout << "----------" << std::endl;
				std::vector<int>::iterator _ite = _v.end();
				for (std::vector<int>::iterator _it = _v.begin(); _it != _ite; _it++)
				{
					std::cout << *_it << std::endl;
				}	
			}
			std::cout << "STD vector(10, 4) capacity = " << _v.capacity() << std::endl;
			std::cout << "STD vector(10, 4) size = " << _v.size() << std::endl;
			std::cout << "STD vector(10, 4) max_size = " << _v.max_size() << std::endl;
			std::cout << "FT vector(10, 4) capacity = " << v.capacity() << std::endl;
			std::cout << "FT vector(10, 4) size = " << v.size() << std::endl;
			std::cout << "FT vector(10, 4) max_size = " << v.max_size() << std::endl;
			std::cout << "----------" << std::endl;
			_v.resize(5);
			v.resize(5);
			{
				Vector<int>::iterator ite = v.end();
				for (Vector<int>::iterator it = v.begin(); it != ite; it++)
				{
					std::cout << *it << std::endl;
				}
				std::cout << "----------" << std::endl;
				std::vector<int>::iterator _ite = _v.end();
				for (std::vector<int>::iterator _it = _v.begin(); _it != _ite; _it++)
				{
					std::cout << *_it << std::endl;
				}	
			}
			std::cout << "STD vector(10, 4) capacity = " << _v.capacity() << std::endl;
			std::cout << "STD vector(10, 4) size = " << _v.size() << std::endl;
			std::cout << "STD vector(10, 4) max_size = " << _v.max_size() << std::endl;
			std::cout << "FT vector(10, 4) capacity = " << v.capacity() << std::endl;
			std::cout << "FT vector(10, 4) size = " << v.size() << std::endl;
			std::cout << "FT vector(10, 4) max_size = " << v.max_size() << std::endl;
		}
		{
			std::cout << "----------PUSH----------" << std::endl;
			std::vector<int> _v;
			Vector<int> v;
			std::cout << "STD vector(10, 4) capacity = " << _v.capacity() << std::endl;
			std::cout << "STD vector(10, 4) size = " << _v.size() << std::endl;
			std::cout << "STD vector(10, 4) max_size = " << _v.max_size() << std::endl;
			std::cout << "FT vector(10, 4) capacity = " << v.capacity() << std::endl;
			std::cout << "FT vector(10, 4) size = " << v.size() << std::endl;
			std::cout << "FT vector(10, 4) max_size = " << v.max_size() << std::endl;
			std::cout << "----------" << std::endl;
			_v.push_back(5);
			_v.push_back(5);
			_v.push_back(5);
			_v.push_back(5);
			_v.push_back(5);
			_v.push_back(5);
			_v.push_back(5);
			_v.push_back(5);
			_v.push_back(5);
			_v.push_back(5);
			_v.push_back(5);
			_v.push_back(5);
			_v.push_back(5);
			_v.push_back(5);
			_v.push_back(5);
			_v.push_back(5);
			_v.push_back(5);
			v.push_back(5);
			v.push_back(5);
			v.push_back(5);
			v.push_back(5);
			v.push_back(5);
			v.push_back(5);
			v.push_back(5);
			v.push_back(5);
			v.push_back(5);
			v.push_back(5);
			v.push_back(5);
			v.push_back(5);
			v.push_back(5);
			v.push_back(5);
			v.push_back(5);
			v.push_back(5);
			v.push_back(5);
			_v.pop_back();
			_v.pop_back();
			v.pop_back();
			v.pop_back();
			std::cout << "STD vector(10, 4) capacity = " << _v.capacity() << std::endl;
			std::cout << "STD vector(10, 4) size = " << _v.size() << std::endl;
			std::cout << "STD vector(10, 4) max_size = " << _v.max_size() << std::endl;
			std::cout << "FT vector(10, 4) capacity = " << v.capacity() << std::endl;
			std::cout << "FT vector(10, 4) size = " << v.size() << std::endl;
			std::cout << "FT vector(10, 4) max_size = " << v.max_size() << std::endl;
		}
		{
			std::cout << "----------CAPACITY----------" << std::endl;
			std::vector<int>::size_type sz;

			std::vector<int> foo;
			sz = foo.capacity();
			std::cout << "making foo grow:\n";
			for (int i=0; i<100; ++i) {
				foo.push_back(i);
				if (sz != foo.capacity())
				{
					sz = foo.capacity();
					std::cout << "capacity changed: " << sz << '\n';
				}
			}

			std::vector<int> bar;
			sz = bar.capacity();
			bar.reserve(100);   // this is the only difference with foo above
			std::cout << "STD vector(10, 4) capacity = " << bar.capacity() << std::endl;
			std::cout << "STD vector(10, 4) size = " << bar.size() << std::endl;
			std::cout << "STD vector(10, 4) max_size = " << bar.max_size() << std::endl;
			std::cout << "making bar grow:\n";
			for (int i=0; i<100; ++i) {
				bar.push_back(i);
				if (sz != bar.capacity())
				{
					sz = bar.capacity();
					std::cout << "capacity changed: " << sz << '\n';
				}
			}
			std::cout << "STD vector(10, 4) capacity = " << bar.capacity() << std::endl;
			std::cout << "STD vector(10, 4) size = " << bar.size() << std::endl;
			std::cout << "STD vector(10, 4) max_size = " << bar.max_size() << std::endl;

			std::cout << "---------" << std::endl;
			
			size_t _sz;

			Vector<int> _foo;
			_sz = _foo.capacity();
			std::cout << "making foo grow:\n";
			for (int i=0; i<100; ++i) {
				_foo.push_back(i);
				if (_sz != _foo.capacity()) 
				{
					_sz = _foo.capacity();
					std::cout << "capacity changed: " << _sz << '\n';
				}
			}

			Vector<int> _bar;
			_sz = _bar.capacity();
			_bar.reserve(100);   // this is the only difference with foo above
			std::cout << "FT vector(10, 4) capacity = " << _bar.capacity() << std::endl;
			std::cout << "FT vector(10, 4) size = " << _bar.size() << std::endl;
			std::cout << "FT vector(10, 4) max_size = " << _bar.max_size() << std::endl;
			std::cout << "making bar grow:\n";
			for (int i=0; i<100; ++i) {
				_bar.push_back(i);
				if (_sz != _bar.capacity())
				{
					_sz = _bar.capacity();
					std::cout << "capacity changed: " << _sz << '\n';
				}
			}
			std::cout << "FT vector(10, 4) capacity = " << _bar.capacity() << std::endl;
			std::cout << "FT vector(10, 4) size = " << _bar.size() << std::endl;
			std::cout << "FT vector(10, 4) max_size = " << _bar.max_size() << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
}
