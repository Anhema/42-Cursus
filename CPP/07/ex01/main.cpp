/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 10:24:56 by aherrero          #+#    #+#             */
/*   Updated: 2022/11/19 21:54:46 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

class Awesome
{
	public:
		Awesome( void ) : _n( 42 ) { return; }
		int get( void ) const { return this->_n; }
	private:
		int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) 
{
	o << rhs.get();
	return o; 
}

template< typename T >
void print( T const & x )
{
	std::cout << x << std::endl;
	return;
}

template< typename T >
void sum( const T & x )
{
	std::cout << x + 1 << std::endl;
	return;
}

int main (void)
{
	std::cout << std::endl;
	std::cout << "--------INT--------" << std::endl << std::endl;
	{
		int	i[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

		std::cout << std::endl << "Print:" << std::endl;
		iter<int>(i, 10, print);
		std::cout << std::endl << "SUM:" << std::endl;
		iter<int>(i, 10, sum);
	}
	std::cout << std::endl << "--------Char--------" << std::endl << std::endl;
	{
		char	i[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

		iter<char>(i, 10, print);
		std::cout << std::endl << "SUM:" << std::endl;
		iter<char>(i, 10, sum);
	}
	std::cout << std::endl << "--------Float--------" << std::endl << std::endl;
	{
		float	i[10] = {0.1f, 1.2524f, 2.3765f, 3.44f, 4.5876f, 5.69659f, 6.79855f, 7.82342f, 8.91341f, 9.90078f};

		iter<float>(i, 10, print);
	}
	std::cout << std::endl << "--------String--------" << std::endl << std::endl;
	{
		std::string	i[10] = {"0.1f", "1.2524ffasdgasgag", "2.3765f", "3.44f", "4.5876f"};

		iter<std::string>(i, static_cast<size_t>(i->length()), print);
	}
	std::cout << std::endl << "--------Correction PDF--------" << std::endl << std::endl;
	{
		int tab[] = { 0, 1, 2, 3, 4 }; // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
		Awesome tab2[5];
		iter( tab, 5, print );
		iter( tab2, 5, print );
	}
	return (0);
}
