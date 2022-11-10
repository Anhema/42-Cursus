/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrero <aherrero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:04:43 by aherrero          #+#    #+#             */
/*   Updated: 2022/11/05 10:38:23 by aherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOT_HPP
#define ROBOT_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm: public Form
{
private:
	std::string target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const & src);
	~RobotomyRequestForm();

	RobotomyRequestForm & operator=(const RobotomyRequestForm & rhs);

	void	execute(Bureaucrat const &executor) const;
	std::string	GetTarget(void) const;
	
	class RobotomizedException: public std::exception
	{
		public:
			virtual const char* what() const throw() // understand better
			{
				return ("Failure");
			}
	};
};

std::ostream & operator<<(std::ostream & o, RobotomyRequestForm & i);

#endif
