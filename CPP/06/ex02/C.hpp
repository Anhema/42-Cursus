/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:20:51 by aherrero          #+#    #+#             */
/*   Updated: 2022/11/13 17:54:56 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_HPP
#define C_HPP

#include "Base.hpp"

class C: public Base
{
	public:
		C(void);
		C(const C &src);
		~C(void);

		C & operator=(const C & rhs);
	private:
};

std::ostream & operator<<(std::ostream & o, C & i);

#endif
