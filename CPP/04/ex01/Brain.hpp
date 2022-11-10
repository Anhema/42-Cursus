/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:05:55 by aherrero          #+#    #+#             */
/*   Updated: 2022/10/05 19:51:15 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
 #define BRAIN_HPP

#include <iostream>

class Brain
{
	public:
		Brain(void);
		Brain(Brain const &src);
		~Brain(void);
		Brain & operator=(Brain const & rhs);

		std::string ideas[100];
};

std::ostream & operator<<(std::ostream & o, Brain & i);

#endif
