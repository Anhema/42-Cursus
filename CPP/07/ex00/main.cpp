/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:19:34 by aherrero          #+#    #+#             */
/*   Updated: 2022/11/19 21:46:07 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

class Awesome
{
	public:
		Awesome(void) : _n(0) {}
		Awesome(int n):_n(n){}
		Awesome & operator= (Awesome & a) { _n = a._n; return *this; }
		bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
		bool operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); }
		bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }

		bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
		bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
		bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
		int get_n() const { return _n; }
	private:
		int _n;
};
std::ostream & operator<<(std::ostream & o, const Awesome &a)
{
	o << a.get_n(); return o;
}

// int main(void)
// {
// 	Awesome a(2), b(4);
// 	swap(a, b);
// 	std::cout << a << " " << b << std::endl;
// 	std::cout << max(a, b) << std::endl;
// 	std::cout << min(a, b) << std::endl;
// 	return (0);
// }



int main( void )
{
	std::cout << std::endl;
	int a = 2;
	int b = 3;
	swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << min<int>( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << max<int>( a, b ) << std::endl;
	swap<int>(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << std::endl << "----------------------------" << std::endl << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	std::cout << "c = " << c << ", d = " << d << std::endl;
	swap<char>(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << min<std::string>( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << max<std::string>( c, d ) << std::endl;
	std::cout << std::endl << "----------------------------" << std::endl << std::endl;
	Awesome e(2), f(4);
	swap(e, f);
	std::cout << e << " " << f << std::endl;
	std::cout << max(e, f) << std::endl;
	std::cout << min(e, f) << std::endl;
	std::cout << std::endl << "----------------------------" << std::endl << std::endl;

	return 0;
}
