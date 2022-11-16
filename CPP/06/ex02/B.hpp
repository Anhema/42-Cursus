/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:20:22 by aherrero          #+#    #+#             */
/*   Updated: 2022/11/13 17:54:35 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_HPP
#define B_HPP

#include "Base.hpp"

class B: public Base
{
	public:
		B(void);
		B(const B &src);
		~B(void);
		
		B & operator=(const B & rhs);
	private:
};

std::ostream & operator<<(std::ostream & o, B & i);

#endif
