/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:38:12 by aherrero          #+#    #+#             */
/*   Updated: 2022/09/21 18:44:31 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
 #define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed(void);
		Fixed(int i);
		Fixed(float i);
		Fixed(Fixed const & src);
		~Fixed(void);

		Fixed & operator=(Fixed const & rhs);
		
		int getRawBits(void) const;
		void setRawBits (int const raw);
		void setRawBits (float const raw);
		float toFloat( void ) const;
		int toInt( void ) const;
		
	private:
		int					i;
		static const int	bits = 8;
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif
