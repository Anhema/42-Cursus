/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:19:22 by aherrero          #+#    #+#             */
/*   Updated: 2022/11/13 17:54:49 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_HPP
#define A_HPP

#include "Base.hpp"

class A: public Base
{
	public:
		A(void);
		A(const A &src);
		~A();

		A & operator=(const A & rhs);
	private:
};

std::ostream & operator<<(std::ostream & o, A & i);

#endif
